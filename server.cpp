//
// server.cpp
// ~~~~~~~~~~
//
// Copyright (c) 2003-2008 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <ctime>
#include <iostream>
#include <string>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>
#include "car_state.hpp"

using boost::asio::ip::udp;

class udp_server
{
public:
  udp_server(boost::asio::io_service& io_service)
    : socket_(io_service, udp::endpoint(udp::v4(), 4001))
  {
    start_receive();
  }

private:
  CarState cars_instance;
  int connected_cars = 0;
  udp::socket socket_;
  udp::endpoint remote_endpoint_;
  boost::array<float, 1024> recv_buffer_;

  void start_receive()
  {
    socket_.async_receive_from(
        boost::asio::buffer(recv_buffer_), remote_endpoint_,
        boost::bind(&udp_server::handle_receive, this,
          boost::asio::placeholders::error,
          boost::asio::placeholders::bytes_transferred));
  }

  void handle_receive(const boost::system::error_code& error,
      std::size_t bytes_transferred)
  {

    // std::cout.write(recv_buffer_.data(), bytes_transferred);
    // std::cout << "byte : " << recv_buffer_.data() << " size : " << bytes_transferred << std::endl;
    float *recv_bytes = recv_buffer_.data();

    // CarState cars[MAX_CARS];
    // cars[connected_cars].updateCarState(recv_bytes);
    cars_instance.updateCarState(recv_bytes);
    connected_cars++;

    typedef std::map<float,Car>::iterator it_type;
    auto cars = cars_instance.getCars();
    for(it_type iterator = cars.begin(); iterator != cars.end();iterator++){
      std::cout << "Car identifier : " << iterator->first;
      std::cout << " ==> (" << iterator->second.x << " , " << iterator->second.y << " )" << std::endl;
    }


    if (!error || error == boost::asio::error::message_size)
    {
      boost::shared_ptr<std::string> message(
          new std::string("Receieved packet"));

      socket_.async_send_to(boost::asio::buffer(*message), remote_endpoint_,
          boost::bind(&udp_server::handle_send, this, message,
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred));

      std::cout << "============================" << std::endl;

      start_receive();
    }
  }

  void handle_send(boost::shared_ptr<std::string> /*message*/,
      const boost::system::error_code& /*error*/,
      std::size_t /*bytes_transferred*/)
  {
  }


};

int main()
{
  try
  {
    boost::asio::io_service io_service;
    udp_server s(io_service);
    io_service.run();
  }
  catch (std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}