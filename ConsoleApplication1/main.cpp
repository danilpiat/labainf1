#include "acutest.h"

#include "TestInt.h"
#include "TestAnimal.h"


TEST_LIST =
{
    {     "IntArraySequence",  Test_IntArraySequence     },
    {      "IntListSequence",  Test_IntListSequence      },
    {    "NodeSeq"           , Test_IntNodeSequence      },
    {  "AnimalArraySequence",  Test_AnimalArraySequence  },
    {   "AnimalListSequence",  Test_AnimalListSequence   },
	{   "time ",  Test_TimeExe   },
    {                nullptr,  nullptr                   }
}
;
