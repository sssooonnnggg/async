// Copyright (c) 2022 Klemens D. Morgenstern
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/async.hpp>
#include <boost/async/main.hpp>
#include <boost/asio/steady_timer.hpp>


boost::async::main co_main(int argc, char *argv[])
{
  boost::asio::steady_timer tim{co_await boost::asio::this_coro::executor, std::chrono::milliseconds(50)};
  co_await tim.async_wait(boost::async::use_op);

  co_return 0;
}
