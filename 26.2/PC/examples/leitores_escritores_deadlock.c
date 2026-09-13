bd
mutex
turno

leitor() {
    while(1) {
        lock(turno)
            leitores++
            if (leitores == 1)
                lock(bd)
        unlock(turno)

        read_data_base(i)

        lock(mutex)
            leitores--
            if (leitores == 0)
                unlock(bd)
        unlock(mutex)

        use_data_read(i);
    }
    pthread_exit(0);
}

escritor() {
    while(1) {
        think_up_data(i)

        lock(turno)
        locK(bd)
            write_data_base(i)
        unlock(bd)
        unlock(turno)
        
    }
    pthread_exit(0)
}