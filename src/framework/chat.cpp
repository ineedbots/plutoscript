#include "stdinc.hpp"
#include "chat.hpp"

void chat::say_all(const std::string& message)
{
    say_all("console", message);
}

void chat::say_all(const std::string& name, const std::string& message)
{
    raw_say_all(name + ": " + message);
}

void chat::say_to(int entnum, const std::string& message)
{
    say_to(entnum, "console", message);
}

void chat::say_to(int entnum, const std::string& name, const std::string& message)
{
    raw_say_to(entnum, name + ": " + message);
}
void chat::raw_say_all(const std::string& message)
{
    game::SV_GameSendServerCommand(-1, game::SV_CMD_CAN_IGNORE, utils::string::va("%c \"%s\"", 84, message.data()));
}

void chat::raw_say_to(int entnum, const std::string& message)
{
    game::SV_GameSendServerCommand(entnum, game::SV_CMD_CAN_IGNORE, utils::string::va("%c \"%s\"", 84, message.data()));
}
