#ifndef TESTANIMAL_H
#define TESTANIMAL_H


#include "acutest.h"

#include "ArraySequence.h"
#include "ListSequence.h"
#include "Animal.h"


void Test_AnimalArraySequence(void)
{
    ArraySequence<Animal>* sequence = new ArraySequence<Animal>();

    Animal l {  "Lion",  1 },
           t { "Tiger",  3 },
           v { "Vanya", 18 };

    TEST_CHECK(sequence->getLength() == 0);

    sequence->append(l);

    TEST_CHECK(sequence->getLength() == 1);
    TEST_CHECK(sequence->getFirst() == l);
    TEST_CHECK(sequence->getLast() == l);
    TEST_CHECK(sequence->get(0) == l);
    TEST_EXCEPTION(sequence->get(-1), std::exception);
    TEST_EXCEPTION(sequence->get(1), std::exception);

    sequence->append(t);

    TEST_CHECK(sequence->getLength() == 2);
    TEST_CHECK(sequence->getFirst() == l);
    TEST_CHECK(sequence->getLast() == t);
    TEST_CHECK(sequence->get(0) == l);
    TEST_CHECK(sequence->get(1) == t);
    TEST_EXCEPTION(sequence->get(-1), std::exception);
    TEST_EXCEPTION(sequence->get(2), std::exception);

    sequence->prepend(v);

    TEST_CHECK(sequence->getFirst() == v);
    TEST_CHECK(sequence->getLast() == t);
    TEST_CHECK(sequence->get(0) == v);
    TEST_CHECK(sequence->get(1) == l);
    TEST_EXCEPTION(sequence->get(-1), std::exception);
    TEST_EXCEPTION(sequence->get(3), std::exception);

    ArraySequence<Animal>* subsequence = dynamic_cast<ArraySequence<Animal>*>(sequence->getSubsequence(1, 1));

    TEST_CHECK(subsequence->getLength() == 1);
    TEST_CHECK(subsequence->getFirst() == l);
    TEST_CHECK(subsequence->getLast() == l);

    subsequence->remove(l);

    TEST_CHECK(subsequence->getIsEmpty());

    delete subsequence;
    delete sequence;
}


void Test_AnimalListSequence(void)
{
    ListSequence<Animal>* sequence = new ListSequence<Animal>();

    Animal l {  "Eefant",  1 },
           t { "Wolf",  3 },
           v { "Frog", 18 };

    TEST_CHECK(sequence->getLength() == 0);

    sequence->append(l);

    TEST_CHECK(sequence->getLength() == 1);
    TEST_CHECK(sequence->getFirst() == l);
    TEST_CHECK(sequence->getLast() == l);
    TEST_CHECK(sequence->get(0) == l);
    TEST_EXCEPTION(sequence->get(-1), std::exception);
    TEST_EXCEPTION(sequence->get(1), std::exception);

    sequence->append(t);

    TEST_CHECK(sequence->getLength() == 2);
    TEST_CHECK(sequence->getFirst() == l);
    TEST_CHECK(sequence->getLast() == t);
    TEST_CHECK(sequence->get(0) == l);
    TEST_CHECK(sequence->get(1) == t);
    TEST_EXCEPTION(sequence->get(-1), std::exception);
    TEST_EXCEPTION(sequence->get(2), std::exception);

    sequence->prepend(v);

    TEST_CHECK(sequence->getFirst() == v);
    TEST_CHECK(sequence->getLast() == t);
    TEST_CHECK(sequence->get(0) == v);
    TEST_CHECK(sequence->get(1) == l);
    TEST_EXCEPTION(sequence->get(-1), std::exception);
    TEST_EXCEPTION(sequence->get(3), std::exception);

    ListSequence<Animal>* subsequence = dynamic_cast<ListSequence<Animal>*>(sequence->getSubsequence(1, 1));

    TEST_CHECK(subsequence->getLength() == 1);
    TEST_CHECK(subsequence->getFirst() == l);
    TEST_CHECK(subsequence->getLast() == l);

    subsequence->remove(l);

    TEST_CHECK(subsequence->getIsEmpty());

    delete subsequence;
    delete sequence;
}


#endif // TESTANIMAL_H
