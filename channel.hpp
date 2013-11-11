#ifndef GSC_CHANNEL_CPP
#define GSC_CHANNEL_CPP

#include <list>
#include <mutex>
#include <condition_variable>

namespace gsc {

#define ERROR_GET_FROM_CLOSED_QUEUE "Error: calling get() on a closed queue"
#define ERROR_PUT_TO_CLOSED_QUEUE "Error: calling put() on a closed queue"

template<typename T>
class Channel {

private:
  std::list<T> queue;
  std::mutex m;
  std::condition_variable cv;
  bool closed;

public:
  Channel();

  T get(bool wait = true);

  void put(T elem);

  // void close();

  // bool is_closed();

};

}

#endif // GSC_CHANNEL_CPP