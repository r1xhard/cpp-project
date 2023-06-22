#include "ringbuffer.h"


ringbuffer::ringbuffer(){
    ringbuffer::head = 0;
    ringbuffer::tail = 0;
    memset(ringbuffer::buffer, 0, sizeof(ringbuffer));

}


void ringbuffer::ringbuffer_add(char zeichen){
    ringbuffer::buffer[ringbuffer::head] = zeichen;
    ringbuffer::head += 1;
    if(ringbuffer::head>=512) ringbuffer:: head = 0;

}

/** Versucht ein Zeichen in den Puffer aufzunehmen
 *  @param[in] zeichen Ein einzelnes Zeichen
 *  @return 0, wenn das Zeichen gespiechert wurde, -1 wenn das nicht funktioniert hat
 */
char ringbuffer::ringbuffer_get(){
    char output = ringbuffer::buffer[ringbuffer::tail];
    ringbuffer::tail++;
    if(ringbuffer::tail>=512) ringbuffer::tail=0;
    return output;
}
