![](https://tcs.teambition.net/storage/31218caf591da88d4d88a641489cb5250a34?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMDgxMzE5MSwiaWF0IjoxNjEwMjA4MzkxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4Y2FmNTkxZGE4OGQ0ZDg4YTY0MTQ4OWNiNTI1MGEzNCJ9.DK5dupwaNPtmZvoud3oyqwR4bchg8QldgQm4eEyoke0&download=2020-09-17+175854.png "")



![](https://tcs.teambition.net/storage/31216e6f2fcbbfbe7a3026c76fa05324c232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMDgxMzAzOSwiaWF0IjoxNjEwMjA4MjM5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE2ZTZmMmZjYmJmYmU3YTMwMjZjNzZmYTA1MzI0YzIzMiJ9.8k1N9z5BpBF6ENsQ0-TTmaKwTnvc8P0Zu7Q0GMKUwIg&download=image.png "")

![](https://tcs.teambition.net/storage/312191a9d08a2c3cad955765fdbfce3f9111?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMDgxMzA0OSwiaWF0IjoxNjEwMjA4MjQ5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5MWE5ZDA4YTJjM2NhZDk1NTc2NWZkYmZjZTNmOTExMSJ9.QO-24ximbCzxSk4D2tEthYwQR8owHeISVEqhYSOMyqE&download=image.png "")

```java
        SortBuilder sortBuilder = null;
        if (sort.equals("c")) {
            sortBuilder = new FieldSortBuilder("sellCounts")
                    .order(SortOrder.DESC);
        } else if (sort.equals("p")) {
            sortBuilder = new FieldSortBuilder("price")
                    .order(SortOrder.ASC);
        } else {
            sortBuilder = new FieldSortBuilder("itemName.keyword")
                    .order(SortOrder.ASC);
        }

```

```java
                .withSort(sortBuilder)
//                .withSort(sortBuilderAge)

```

![](https://tcs.teambition.net/storage/3121cba74ad6a190d185e242fb55be48e105?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMDgxMzExOCwiaWF0IjoxNjEwMjA4MzE4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFjYmE3NGFkNmExOTBkMTg1ZTI0MmZiNTViZTQ4ZTEwNSJ9.VYRcwrgR1SaUlsqf0pd2ohG2GC9ALYKNs3X4TUjhKeY&download=image.png "")

![](https://tcs.teambition.net/storage/3121eab14561a575e7c4febeb39577b6add2?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMDgxMzEzMCwiaWF0IjoxNjEwMjA4MzMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlYWIxNDU2MWE1NzVlN2M0ZmViZWIzOTU3N2I2YWRkMiJ9.oG6796Ox1Iqjz81KN4OInNhf1OqRSQWjJQWRAyYi1Fs&download=image.png "")

![](https://tcs.teambition.net/storage/3121b50c82dd9ebb43a9b21d2660e32ae979?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMDgxMzEzOCwiaWF0IjoxNjEwMjA4MzM4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiNTBjODJkZDllYmI0M2E5YjIxZDI2NjBlMzJhZTk3OSJ9.jSfR_pfjVe9hXBe0RhjCvv2XhMDXBRzk7eMTfk7Jtcw&download=image.png "")

![](https://tcs.teambition.net/storage/3121f469bc128b0e3b19c7868c812a1295a5?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMDgxMzE1MywiaWF0IjoxNjEwMjA4MzUzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmNDY5YmMxMjhiMGUzYjE5Yzc4NjhjODEyYTEyOTVhNSJ9.Utyhvuqq2xgniCTT4NqTDHvwxq6cA8qEQNV26jWhtn0&download=image.png "")

开源笔记

可 Pull Requests 协作写开源笔记

gitee

[https://gitee.com/opendevel/java-for-linux](https://gitee.com/opendevel/java-for-linux)

github

[https://github.com/OSrcD/java-for-linux](https://github.com/OSrcD/java-for-linux)

teambition

[https://tburl.in/0jDNvpbK](https://tburl.in/0jDNvpbK)

开源视频

bilibili

[https://space.bilibili.com/77266754](https://space.bilibili.com/77266754)

开源博客

oschina

[https://my.oschina.net/u/4675154](https://my.oschina.net/u/4675154)

csdn

[https://blog.csdn.net/OpenDevel](https://blog.csdn.net/OpenDevel)

开源项目

gitee

[https://gitee.com/opendevel](https://gitee.com/opendevel)

github

[https://github.com/OSrcD](https://github.com/OSrcD)

开源赞赏

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMjgxOCwiaWF0IjoxNjEwMjA4MDE4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.cSMsjoDSCgA8oeEKuacYamfWvsAm9WhPzRcqERTWEz8&download=image.png "")

