#pragma once
class Node
{
public:
    int coefficient;
    int exponent;
    Node* next;
    Node* prev;
    Node(int c, int e);
};