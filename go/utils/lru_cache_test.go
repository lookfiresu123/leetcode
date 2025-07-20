package utils

import (
	"testing"

	"github.com/smartystreets/goconvey/convey"
)

// Test utility function to test Put and Get operations of LRUCache
func TestLRUCachePutGet(t *testing.T) {
	convey.Convey("Test LRUCache Put and Get operations", t, func() {
		cache := NewLRUCache(3)
		cache.Put("1", "1")
		cache.Put("2", "2")
		cache.Put("3", "3")
		cache.Put("4", "4")

		convey.So(cache.Get("1"), convey.ShouldBeNil)
		convey.So(cache.Get("2"), convey.ShouldEqual, "2")
		convey.So(cache.Get("3"), convey.ShouldEqual, "3")
		convey.So(cache.Get("4"), convey.ShouldEqual, "4")
	})
}
