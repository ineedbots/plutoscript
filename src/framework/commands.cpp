#include "stdinc.hpp"
#include "commands.hpp"

void cmd::execute_command(const std::string& command)
{
    game::Cbuf_AddText(game::LOCAL_CLIENT_0, utils::string::va("%s\n", command.data()));
}


/*
bool handle_server_command()
{
    //printf("cmd: %s\n", Cmd_Argv(0));
    return false;
}

bool handle_client_command(int clientNum)
{
    return false;
}

void __declspec(naked) Cmd_ExecuteSingleCommand_stub()
{
    static uintptr_t cancel_ = 0x54637B;
    static uintptr_t continue_ = 0x54632A;

    if (handle_server_command())
    {
        __asm
        {
            push edi
            jmp cancel_
        }
    }
    __asm
    {
        cmp dword ptr ds:[1C97958h], 0
        jmp continue_
    }
}*/

/*iw5::ClientCommand_t ClientCommand_;

void ClientCommand_stub(int clientNum)
{
    char cmd[1024];

    int client = *(int*)(int)(iw5::g_entities + 628 * clientNum) + 344;

    if (client)
    {
        iw5::SV_Cmd_ArgvBuffer(0, cmd, 1024);
            
        // Game ones
        if (!(_stricmp(cmd, "n") && _stricmp(cmd, "say") && _stricmp(cmd, "say_team") && _stricmp(cmd, "s") && _stricmp(cmd, "mr")))
        {
            return ClientCommand_(clientNum);
        }

        // Our handler
        if (!handle_client_command(clientNum))
        {
            const char* unkCmd = utils::string::va("%c \"GAME_UNKNOWNCLIENTCOMMAND\x15%s", 101, cmd);
            iw5::SV_GameSendServerCommand(clientNum, iw5::SV_CMD_CAN_IGNORE, unkCmd);
        }
            
    }
}*/

/* Rekti's call hook on menu response broke this

int* clientNum;

void __declspec(naked) ClientCommand_stub()
{
    __asm
    {
        jnz handler
        push esi
        mov eax, 502230h // call "mr" handler
        call[eax]
        add esp, 4
        jmp finish

        handler:
        mov clientNum, esi
        call handle_client_command

        finish:
        pop edi
        pop esi
        add esp, 400h
        retn
    }
}
*/

//util::hook::jump(0x546323, Cmd_ExecuteSingleCommand_stub);
