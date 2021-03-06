#include "contiki.h"
#include "loader.h"
#include "ctk-term.h"
#include "serial32.h"

/*-----------------------------------------------------------------------------------*/
/* 
 * #defines and enums
 */
/*-----------------------------------------------------------------------------------*/
#define SIO_POLL(c)  (SerialRead(&c) == 1)
#define SIO_SEND(c)  SerialWrite(c)
#define SIO_INIT     SerialOpenPort("COM1")

#ifdef CTK_TERM_CONF_SERIAL_BUFFER_SIZE
#define OUTPUT_BUFFER_SIZE CTK_TERM_CONF_SERIAL_BUFFER_SIZE
#else
#define OUTPUT_BUFFER_SIZE 200
#endif

/*-----------------------------------------------------------------------------------*/
/* 
 * Local variables
 */
/*-----------------------------------------------------------------------------------*/
static ek_id_t id = EK_ID_NONE;

static struct ctk_term_state* termstate;
static unsigned char outbuffer[OUTPUT_BUFFER_SIZE];

EK_POLLHANDLER(pollhandler);
EK_EVENTHANDLER(eventhandler, ev, data);
EK_PROCESS(p, "CTK serial server", EK_PRIO_NORMAL,
	   eventhandler, pollhandler, NULL);

/*-----------------------------------------------------------------------------------*/
/* 
 * Idle function
 */
/*-----------------------------------------------------------------------------------*/
EK_POLLHANDLER(pollhandler)
{
  unsigned char c;
  unsigned short len;
  while(SIO_POLL(c)) {
    ctk_term_input(termstate, c);
  }

  len = ctk_term_send(termstate, outbuffer, OUTPUT_BUFFER_SIZE);
  if (len > 0) {
    unsigned short i;
    for (i=0; i < len; ++i) {
      SIO_SEND(outbuffer[i]);
    }
    ctk_term_sent(termstate);
  }
}

/*-----------------------------------------------------------------------------------*/
/* 
 * Init function
 */
/*-----------------------------------------------------------------------------------*/
LOADER_INIT_FUNC(ctk_termserial_init, arg)
{
  arg_free(arg);
  SIO_INIT;
  termstate = ctk_term_alloc_state();
  if (termstate == NULL) return;
  if(id == EK_ID_NONE) {
    id = ek_start(&p);
  }
}
/*-----------------------------------------------------------------------------------*/
EK_EVENTHANDLER(eventhandler, ev, data)
{

}
