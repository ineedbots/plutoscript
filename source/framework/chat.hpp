#pragma once

namespace chat
{
    void raw_say_all(const std::string& message);
    void say_all(const std::string& name, const std::string& message);
    void say_all(const std::string& message);
    void raw_say_to(int entnum, const std::string& message);
    void say_to(int entnum, const std::string& name, const std::string& message);
    void say_to(int entnum, const std::string& message);
    void init();
}