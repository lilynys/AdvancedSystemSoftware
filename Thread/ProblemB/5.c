sem_t s; /* semaphore s */ void *foo(void *vargp) { int id; P(&s); id = *((int *)vargp); V(&s); printf("Thread %d\n", id); }

int main() { pthread_t tid[2]; int i; sem_init(&s, 0, 1); /* S=1 INITIALLY */ for (i = 0; i < 2; i++) { Pthread_create(&tid[i], 0, foo, &i); } Pthread_join(tid[0], 0); Pthread_join(tid[1], 0); }