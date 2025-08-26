#ifndef _SERVER_H_
#define _SERVER_H_

class Runtime;

/// <summary>
/// Base class for objects that handle individual pieces of logic.
/// </summary>
class Server
{
public:
	Server();
	virtual ~Server();

	virtual void pre_update_server(Runtime* runtime);
	virtual void post_update_server(Runtime* runtime);
};

#endif