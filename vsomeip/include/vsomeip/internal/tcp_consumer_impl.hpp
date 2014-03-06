//
// tcp_consumer_impl.hpp
//
// Author: Lutz Bichler <Lutz.Bichler@bmwgroup.com>
//
// This file is part of the BMW Some/IP implementation.
//
// Copyright �� 2013, 2014 Bayerische Motoren Werke AG (BMW).
// All rights reserved.
//

#ifndef VSOMEIP_INTERNAL_TCP_CONSUMER_IMPL_HPP
#define VSOMEIP_INTERNAL_TCP_CONSUMER_IMPL_HPP

#include <boost/array.hpp>
#include <boost/asio/ip/tcp.hpp>

#include <vsomeip/config.hpp>
#include <vsomeip/internal/consumer_base_impl.hpp>

namespace vsomeip {

class endpoint;

class tcp_consumer_impl
		: virtual public consumer_base_impl {
public:
	tcp_consumer_impl(
			factory *_factory,
			const endpoint *_endpoint,
			boost::asio::io_service &_is);
	virtual ~tcp_consumer_impl();

	void start();
	void stop();

	void connect();
	void receive();

private:
	void restart();
	void send_queued();

	ip_address get_remote_address() const;
	ip_port get_remote_port() const;
	ip_protocol get_protocol() const;
	ip_version get_version() const;

	const uint8_t * get_received() const;

	bool is_magic_cookie(
			message_id _message_id, length _length, request_id _request_id,
			protocol_version _protocol_version, interface_version _interface_version,
			message_type _message_type, return_code _return_code) const;
	void send_magic_cookie();

private:
	boost::asio::ip::tcp::socket socket_;
	boost::asio::ip::tcp::endpoint local_endpoint_;

	boost::array< uint8_t, VSOMEIP_MAX_TCP_MESSAGE_SIZE > received_;
};

} // namespace vsomeip

#endif // VSOMEIP_INTERNAL_TCP_CONSUMER_IMPL__HPP