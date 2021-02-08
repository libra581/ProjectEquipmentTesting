#include "ExeptionInputData.h"

ExeptionInputData::ExeptionInputData(const QString &textExcept) :
    textExcept(textExcept)
{
}

const QString & ExeptionInputData::whatIs() const
{
    return this->textExcept;
}

void ExeptionInputData::raise() const
{
    throw *this;
}

ExeptionInputData *ExeptionInputData::clone() const
{
    return new ExeptionInputData(*this);
}
