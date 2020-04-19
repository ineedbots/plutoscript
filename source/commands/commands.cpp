#include "stdinc.hpp"
#include "commands.hpp"

namespace commands
{
	void execute_command(const std::string& command)
	{
		Cbuf_AddText(LOCAL_CLIENT_0, command.c_str());
	}

    void raw_say_all(const std::string& message)
    {
        SV_GameSendServerCommand(-1, SV_CMD_CAN_IGNORE, util::string::va("%c \"%s\"", 84, message.c_str()));
    }

    void say_all(const std::string& name, const std::string& message)
    {
        raw_say_all(name + ": " + message);
    }

    void say_all(const std::string& message)
    {
        say_all("console", message);
    }

    void raw_say_to(int entnum, const std::string& message)
    {
        SV_GameSendServerCommand(entnum, SV_CMD_CAN_IGNORE, util::string::va("%c \"%s\"", 84, message.c_str()));
    }

    void say_to(int entnum, const std::string& name, const std::string& message)
    {
        raw_say_to(entnum, name + ": " + message);
    }

    void say_to(int entnum, const std::string& message)
    {
        say_to(entnum, "console", message);
    }

	void init()
	{

	}
}
