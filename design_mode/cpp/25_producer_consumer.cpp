// ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

// �ο������ģʽ - ������ģʽ

#include <iostream>
#include <vector>
#include <cstdlib>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>


#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif

static const int g_item_queue_size_rel = 3;                      // ����ʵ�ʴ�С
static const int g_item_queue_size = g_item_queue_size_rel + 1;  // �����жϵĶ��������߼�����
static const int g_item_to_produce = 10;                         // ����������
std::mutex g_mutex;                                              // ���ڶ��߳�ͬ���������ֹ��־����

struct ItemQueue {
  int item_buffer[g_item_queue_size];  // �������ѻ����������������ݴ浽�˴��������ߴӴ˴������ݡ�
  size_t read_position;                // ���λ�������ߴ������л�ȡ���ݵ�λ��
  size_t write_position;               // ���λ�����������������ݷŵ�������
  std::mutex queue_mtx;                // ������������������ֹ���������ݻ���
  std::condition_variable queue_not_full;   // ������������ʾ�������Ƿ�����
  std::condition_variable queue_not_empty;  // ������������ʾ�������Ƿ�Ϊ��
} g_item_queue;


// ���ɲ�Ʒ��ʵ��
void ProductItem(ItemQueue* iq, int item) {
  std::unique_lock<std::mutex> queue_lock(iq->queue_mtx);
  // �ж� queue �Ƿ������������������ while �ȴ�
  while (((iq->write_position + 1) % g_item_queue_size) == iq->read_position) {
    {
      std::lock_guard<std::mutex> lock(g_mutex);
      std::cout << "�����������ȴ�..." << std::endl;
    }
    (iq->queue_not_full).wait(queue_lock);
  }

  // queue ��Ϊ�գ�����д���Ʒ
  (iq->item_buffer)[iq->write_position] = item;

  // д����λ��1
  (iq->write_position)++;

  if (iq->write_position == g_item_queue_size) {
    // �������趨д��λ��Ϊ��ʼλ��
    iq->write_position = 0;
  }

  (iq->queue_not_empty).notify_all(); // ֪ͨ�����ߣ����в�Ϊ��
  queue_lock.unlock();
}

// ���Ѳ�Ʒ��ʵ��
int ConsumeItem(ItemQueue* iq) {
  int data = -1;
  std::unique_lock<std::mutex> queue_lock(iq->queue_mtx);
  // �ж� queue �Ƿ�Ϊ�գ��յ�ʱ�򣬵ȴ�
  while (iq->read_position == iq->write_position) {
    {
      std::lock_guard<std::mutex> lock(g_mutex);
      std::cout << "�������գ��ȴ�..." << std::endl;
    }
    (iq->queue_not_empty).wait(queue_lock);
  }

  data = (iq->item_buffer)[iq->read_position]; // ��ȡ��Ʒ

  (iq->read_position)++;

  if (iq->read_position == g_item_queue_size) {
    iq->read_position = 0;
  }

  (iq->queue_not_full).notify_all();
  queue_lock.unlock();

  return data;
}

// ����������
void ProducerTask() {
  for (int n = 1; n <= g_item_to_produce; n++) {
    ProductItem(&g_item_queue, n);
    {
      std::lock_guard<std::mutex> lock(g_mutex);
      std::cout << "���ɲ�Ʒ��" << n << " " << std::endl;
    }
  }
}

void ConsumerTask() {
  static int consume_count = 0;
  while (1) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    int item = ConsumeItem(&g_item_queue);
    {
      std::lock_guard<std::mutex> lock(g_mutex);
      std::cout << "���Ѳ�Ʒ��" << item << " " << std::endl;
    }
    if (++consume_count == g_item_to_produce) {
      // �����������������˳�
      break;
    }
  }
}

void  InitItemQueue(ItemQueue* iq) {
  iq->write_position = 0;
  iq->write_position = 0;
}

int main()
{
  InitItemQueue(&g_item_queue);
  std::thread producer_thread(ProducerTask);
  std::thread consumer_thread(ConsumerTask);

  producer_thread.join();
  consumer_thread.join();

	return 0;
}
