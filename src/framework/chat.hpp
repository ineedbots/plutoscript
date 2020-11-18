#pragma once

class chat
{
public:
    static void say_all(const std::string& message);
    static void say_all(const std::string& name, const std::string& message);

    static void say_to(int entnum, const std::string& message);
    static void say_to(int entnum, const std::string& name, const std::string& message);

    static void raw_say_all(const std::string& message);
    static void raw_say_to(int entnum, const std::string& message);  
};
