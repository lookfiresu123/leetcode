package test

import (
	"net/http"
	_ "net/http/pprof"
	"sync"
	"time"
)

func PprofTest() {
	var wg sync.WaitGroup
	wg.Add(1)
	go func() {
		defer wg.Done()
		http.ListenAndServe("localhost:6060", nil)
	}()

	wg.Add(1)
	go func() {
		defer wg.Done()
		time.Sleep(60 * time.Second)
	}()
	wg.Wait()
}
