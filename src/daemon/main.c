/* -*- mode: c; c-file-style: "openbsd" -*- */
#include "lldpd.h"
#include "aasdk_comm.h"
#include <pthread.h>
#include "aasdk_time_comm.h"

void *clock_thread(void *arg);
void aatransi_initialize(void);
void aatransi_time_tick(struct timespec *curr);

/**
 * @mainpage
 *
 * lldpd is an implementation of 802.1AB (aka LLDP). It provides an interface
 * for third party clients to interact with it: querying neighbors, setting some
 * TLV. This interface is included into a library whose API can be found in @ref
 * liblldpctl
 */

int
main(int argc, char **argv, char **envp)
{
  int       aa_rc; /* AASDK ret code */
  pthread_t pt_id; /* pthread ID */

  aasdki_output_set(-1, printf);
  aatransi_initialize();

  aa_rc = aasdki_global_init();

  printf("aasdk: aasdki_global_init() = %d\n", aa_rc);

  /* start the clock thread */

  pthread_create(&pt_id, NULL, clock_thread, NULL);

  return lldpd_main(argc, argv, envp);
}

void *
clock_thread(void *arg)
{
  struct timespec cur_time;
  struct timespec new_time;
  struct timespec sleep_time;
  struct timespec one_sec = {1,0};

  for (;;)
  {
    sleep_time = one_sec;

    aasdkx_time_sleep(&sleep_time);

    aasdku_time_get(&cur_time);

    aasdku_time_add(&new_time, &cur_time, &one_sec);

    aasdki_time_tick(&new_time);
    aatransi_time_tick(&new_time);
  }
}

