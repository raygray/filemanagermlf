//
// 客户端的命令执行
//

#ifndef CLIENTCOMMAND_H
#define CLIENTCOMMAND_H

class ClientCommand
{
public:
    ClientCommand();
    virtual void doCommand() = 0;
};

#endif // CLIENTCOMMAND_H
