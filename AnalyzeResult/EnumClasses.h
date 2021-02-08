#ifndef CODESEXEC_H
#define CODESEXEC_H

enum class CodeExec
{
    ErrorPort   = -3,
    ErrorFile   = -2,
    Error       = -1,
    Success     =  0,
    Waiting     =  1,
    PortEmpty   =  2,
    AnalyzeError=  3,
};


enum class TypeEquipment
{
    BASI,
    BAPPD
};

#endif // CODESEXEC_H
