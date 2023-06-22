#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include <QObject>

class ringbuffer : public QObject

{
public:
    ringbuffer();
    void ringbuffer_add(char zeichen);
    char ringbuffer_get();

protected:
char buffer[512];
int head;
int tail;

};

#endif // RINGBUFFER_H
