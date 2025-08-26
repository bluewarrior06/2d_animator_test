#ifndef _RUNTIME_H_
#define _RUNTIME_H_

/// <summary>
/// Encapsulates runtime logic into a single class.
/// Holds a mainloop method that can be overriden.
/// 
/// 
/// </summary>
class Runtime
{
public:
	Runtime();
	Runtime(Runtime& copy);
	Runtime(Runtime&& move);
	~Runtime();

private:
	bool _is_running = false;
	
	void _mainloop();

public:
	// Begins the mainloop.
	void begin();

	// Ends the mainloop.
	// The mainloop will end once the loop is done processing a loop.
	void end();
};

#endif