#ifndef _SERVER_H_
#define _SERVER_H_

class Runtime;

/// <summary>
/// Base class for objects that handle individual pieces of logic.
/// 
/// Servers should only be constructed by a Runtime class.
/// </summary>
class Server
{
public:
	Server(Runtime* runtime);
	virtual ~Server();
	
	virtual void pre_update(Runtime* runtime);
	virtual void post_update(Runtime* runtime);
};

#endif