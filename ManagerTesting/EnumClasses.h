#ifndef CODESEXEC_H
#define CODESEXEC_H

enum class CodeExec
{
    ErrorPort = -3,
    ErrorFile = -2,
    Error = -1,
    Success,
    Waiting
};


enum class TypeEquipment
{
    BASI,
    BAPPD
};

enum class ServerCodeExec
{
    EAnalyze = -3 ,
    EInputData = -2,
    ECyclegramma = -1,
    Manager = 0  ,
    Cyclegramma = 1,
    InputData = 2,
    Analyze = 3,
};


#endif // CODESEXEC_H
