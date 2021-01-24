![](https://tcs.teambition.net/storage/31214e3790dde2ba02fd9642c56897e45081?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUyOCwiaWF0IjoxNjExNDY1NzI4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0ZTM3OTBkZGUyYmEwMmZkOTY0MmM1Njg5N2U0NTA4MSJ9.AmRpWSlsADJmzWrwaQkDK-9eUOTUgEiM_6pefj_yzUY&download=image.png "")

什么我的



缓存在本地



@CacheResult 标识返回结果是要放到缓存里面的

我要把这个Friend 当做Cache的内容 保存到我的本地Cache当中



@CacheKey 我把这个 String name 作为一个CacheKey 从本地Cache取



@HystrixCommand 只针对一个服务进行降级 就可以在服务上面添加HystrixCommand



fallbackMethod 指定当前降级方案的方法名 如果为abc  在同级的类中就要声明一个 abc的方法名 接收的方法参数也要跟当前的方法参数一致

![](https://tcs.teambition.net/storage/3121fcc1e4bc54fa2ce61e1d6959c0e7901a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUyOCwiaWF0IjoxNjExNDY1NzI4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmY2MxZTRiYzU0ZmEyY2U2MWUxZDY5NTljMGU3OTAxYSJ9.DD1TDmx3Ww_Z4R6r1kAFbiUcB3mq5Kb9gkBJ3vjbZNM&download=image.png "")

commandKey 简化超时配置方式 

![](https://tcs.teambition.net/storage/31214f49ee5dfa3869ae4a07efc0ca46256e?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUyOCwiaWF0IjoxNjExNDY1NzI4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0ZjQ5ZWU1ZGZhMzg2OWFlNGEwN2VmYzBjYTQ2MjU2ZSJ9.bNP1Ot1d1Ni-ux7PC4KiyrMO8y5nFgmGdbBjMb0AeCU&download=image.png "")

在配置文件替换为

![](https://tcs.teambition.net/storage/3121a7b63302810eab984beec8f8baf8c7c2?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUyOCwiaWF0IjoxNjExNDY1NzI4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhN2I2MzMwMjgxMGVhYjk4NGJlZWM4ZjhiYWY4YzdjMiJ9.3h0WX8XAyJCNZFSOyhMC5qcnivXg5H-o-RDrWQGknyk&download=image.png "")

![](https://tcs.teambition.net/storage/3121ee244cfec4e793c044694ee4e5dc6e75?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUyOCwiaWF0IjoxNjExNDY1NzI4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlZTI0NGNmZWM0ZTc5M2MwNDQ2OTRlZTRlNWRjNmU3NSJ9.Yk2l2KMEnriYrLFUkaUogkbbioC-K83xBHnbdUOmUvc&download=image.png "")





Fallback 每一个方法都是一个降级流程

针对MyService 任何方法调用 失败 都会直接找到Fallback对应方法

 

通过 requestCache 方法 我可以让它在同一个上下文当中 只被调用一次



同一个上下文 就是域了

![](https://tcs.teambition.net/storage/31210cf5ee36defafab4ee6ddfd41c3a015b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUyOCwiaWF0IjoxNjExNDY1NzI4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwY2Y1ZWUzNmRlZmFmYWI0ZWU2ZGRmZDQxYzNhMDE1YiJ9.jFCgi8dGrtK_QjQgFrcefbkXRY6NZUvDftfa8tUcZpo&download=image.png "")



Request 的上下文  初始化一个上下文

![](https://tcs.teambition.net/storage/312189093f290635a4f8069a6f643b915d0b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUyOCwiaWF0IjoxNjExNDY1NzI4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4OTA5M2YyOTA2MzVhNGY4MDY5YTZmNjQzYjkxNWQwYiJ9.MkwCPaoPOfDlNEMAsUzE0bUWuu2ahBGSws4U-tTH6I0&download=image.png "")

上下文 就是域 就是当前定义起始地方 这个对象的生命周期结束



这个上下文就像文件一样 你把它打开了 最后还要关闭



@Cleanup 它会帮你调用上下文的 close方法

![](https://tcs.teambition.net/storage/31211840d9879c174fdd43c70a819054ef2b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUyOCwiaWF0IjoxNjExNDY1NzI4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExODQwZDk4NzljMTc0ZmRkNDNjNzBhODE5MDU0ZWYyYiJ9.AIi-6int-oL0whYfuvcW41o0ol4Dbxco-G7t7ywhFhk&download=image.png "")

![](https://tcs.teambition.net/storage/3121ca06bf6021b96f388afdf622e8e35751?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUyOCwiaWF0IjoxNjExNDY1NzI4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFjYTA2YmY2MDIxYjk2ZjM4OGFmZGY2MjJlOGUzNTc1MSJ9.SXYv-ZNIrNva2Al1r7JastuSABRVMmAD1R9n-a9T0AI&download=image.png "")



指定方法名



![](https://tcs.teambition.net/storage/3121cf233df2d4f08788d8135daeb20c03a2?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUyOCwiaWF0IjoxNjExNDY1NzI4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFjZjIzM2RmMmQ0ZjA4Nzg4ZDgxMzVkYWViMjBjMDNhMiJ9.tkjG1rIpSxGouuubhgSA_O_HS1e6XBI1wtmY6kLbSsA&download=image.png "")

两个 FeignClient

![](https://tcs.teambition.net/storage/31213d84ce0239043342a315ec74354bbc0b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUyOCwiaWF0IjoxNjExNDY1NzI4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzZDg0Y2UwMjM5MDQzMzQyYTMxNWVjNzQzNTRiYmMwYiJ9.xtaWmMeIIaBcsuzwVg6YegA_ZJz_9Lzdz6xPwgW6smA&download=image.png "")

![](https://tcs.teambition.net/storage/3121a6cb8cf9229f777268a578ea40f1d6e2?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUyOCwiaWF0IjoxNjExNDY1NzI4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhNmNiOGNmOTIyOWY3NzcyNjhhNTc4ZWE0MGYxZDZlMiJ9.h2Vozg50Va2G9SKXufPHL2E6ZjSwhWcTwOy1R9PPuoE&download=image.png "")



Spring 不知道该注入哪一个 会报错

![](https://tcs.teambition.net/storage/3121d953cea07d87d96e6c2054c822335d60?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUyOCwiaWF0IjoxNjExNDY1NzI4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkOTUzY2VhMDdkODdkOTZlNmMyMDU0YzgyMjMzNWQ2MCJ9.zg1N_Mwun51DR0xn5bxsUASsOa3_FIsPv4F6mGAQa_E&download=image.png "")

解决方案

![](https://tcs.teambition.net/storage/3121f7274aa4fed94d59ece30b92bb5fd9c8?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUyOCwiaWF0IjoxNjExNDY1NzI4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmNzI3NGFhNGZlZDk0ZDU5ZWNlMzBiOTJiYjVmZDljOCJ9.NxkN-kYddlKQ4wzRQm8M5due37E3z13sksPc2xHLvBI&download=image.png "")

primary true的作用

要注入IService类型 把 MyService 当做带头大哥



![](https://tcs.teambition.net/storage/3121743ddfd55ccc3a70b540e4523ed65afc?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUyOCwiaWF0IjoxNjExNDY1NzI4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3NDNkZGZkNTVjY2MzYTcwYjU0MGU0NTIzZWQ2NWFmYyJ9.a0TvcM_VhGRrDFNIwQQAw_UeW_7k5GRserDQt9LpsMY&download=image.png "")

默认是true 还要指定为false

![](https://tcs.teambition.net/storage/312168160acac7198162ac78868d29d0dc18?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUyOCwiaWF0IjoxNjExNDY1NzI4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE2ODE2MGFjYWM3MTk4MTYyYWM3ODg2OGQyOWQwZGMxOCJ9.lV_lv-9EdSy_-nobJnN5mQ5GzAUbPsWCGgUMJ9zRZIE&download=image.png "")

这里也要设置为false



![](https://tcs.teambition.net/storage/312186a8f33be24d3e191b5e9ae37ae42eee?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUyOCwiaWF0IjoxNjExNDY1NzI4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4NmE4ZjMzYmUyNGQzZTE5MWI1ZTlhZTM3YWU0MmVlZSJ9.iI8h6i-H02DgTmPg8KmYMRfGiwZyURw-byZyFBqLRRE&download=image.png "")



启动

![](https://tcs.teambition.net/storage/31215d3236504dd28d796fa095b7735c8955?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUyOCwiaWF0IjoxNjExNDY1NzI4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1ZDMyMzY1MDRkZDI4ZDc5NmZhMDk1Yjc3MzVjODk1NSJ9.oTxnrp495uW8LCY74EyvBG922pxzYLtbtJY_h2yJknM&download=image.png "")

![](https://tcs.teambition.net/storage/3121da192a802e5105307519966b92afe649?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUyOCwiaWF0IjoxNjExNDY1NzI4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkYTE5MmE4MDJlNTEwNTMwNzUxOTk2NmI5MmFmZTY0OSJ9.bKUWkT7w5l8pwm2k6L3kzI31e9N-3nhIWwmNSZ2_2VY&download=image.png "")

![](https://tcs.teambition.net/storage/3121e26cf68c707e118c6a387e18dd0a2193?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUyOCwiaWF0IjoxNjExNDY1NzI4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlMjZjZjY4YzcwN2UxMThjNmEzODdlMThkZDBhMjE5MyJ9.euAgtUzLTxuYlTopyTCP5q0nRh7XY-GOpTuZDwsdjyY&download=image.png "")

![](https://tcs.teambition.net/storage/3121d59cc9e6010e3e21aa2418cf5b11416c?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUyOCwiaWF0IjoxNjExNDY1NzI4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkNTljYzllNjAxMGUzZTIxYWEyNDE4Y2Y1YjExNDE2YyJ9.Cpp9VbBOP1ObsW6oTD2vHsNdoQH1l98_0u9Z54xQEis&download=image.png "")

重启

![](https://tcs.teambition.net/storage/312188285812fb9af55c23e221dde925ecf9?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUyOCwiaWF0IjoxNjExNDY1NzI4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4ODI4NTgxMmZiOWFmNTVjMjNlMjIxZGRlOTI1ZWNmOSJ9.Y0FtjQLXyaioaqpvL3ej3QV7r1SqOaDzCSmwp8QLPXU&download=image.png "")

![](https://tcs.teambition.net/storage/31213e7982229fa6e3e8fe709281e7aff64d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUyOCwiaWF0IjoxNjExNDY1NzI4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzZTc5ODIyMjlmYTZlM2U4ZmU3MDkyODFlN2FmZjY0ZCJ9.F8VIJiylkNUipy8cOtlpTYYRO9mryXD9ZltuAi8M56Y&download=image.png "")

两个调用

![](https://tcs.teambition.net/storage/31217126c09b1b2b04a85b0f2eaf40aa09f3?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUyOCwiaWF0IjoxNjExNDY1NzI4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3MTI2YzA5YjFiMmIwNGE4NWIwZjJlYWY0MGFhMDlmMyJ9.nezODjrILRUP27q9PjfH2s9ono8jmU028il9UicqCLU&download=image.png "")

![](https://tcs.teambition.net/storage/312184ce88ead61a0ba6599e27e42963cf16?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUyOCwiaWF0IjoxNjExNDY1NzI4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4NGNlODhlYWQ2MWEwYmE2NTk5ZTI3ZTQyOTYzY2YxNiJ9.r3eAsW7rokZgaKr-panw-xfFiuqmbZI0q8gzhyE1tuA&download=image.png "")

我想在当前方法 调用另外一个方法 这个方法的名称就是叫abc

abc 我还想用这个Friend 

要么改方法的签名 把Friend 传进去 

要么在abc 方法中 再调用一次requestCache 接口 

不管发生几次 只要同在一个Context 上下文中 并不会实际发起远程调用

而是从缓存当中 把这个对象拿出来 这样一来就不必要声明一个接收的参数了 让方法签名看起来 简洁一点 



还有一些情况

可能你在这个方法内 连续调用了 好几个本地的不同服务 这不同的服务中间 都做了一个操作 哪就是调用了 某一个 特定的服务 这时候 我们可以在那个特定的服务上面 把这个注解 @CacheResult @CacheKey 都加上去 让这个服务的返回值 可以被缓存下来 在整个方法的调用链路中 将会节省非常非常多的资源 消耗  将减少好几次远程调用请求

![](https://tcs.teambition.net/storage/3121e72fa90ee719db840992e63530643e6e?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUyOCwiaWF0IjoxNjExNDY1NzI4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlNzJmYTkwZWU3MTlkYjg0MDk5MmU2MzUzMDY0M2U2ZSJ9.gNspl_9-YeH8-39ZiiVhoVwg2ukOalDWf-t4FNyajds&download=image.png "")







![](https://tcs.teambition.net/storage/3121e45c53c9f81af75515622b96efcb41ab?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUyOCwiaWF0IjoxNjExNDY1NzI4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlNDVjNTNjOWY4MWFmNzU1MTU2MjJiOTZlZmNiNDFhYiJ9.M5L2E-9wjt-1-ugZyQS438LUw4JYcbsKD1RI0x_UFJQ&download=image.png "")

```text
spring.application.name=hystrix-consumer
server.port=50000
spring.main.allow-bean-definition-overriding=true
eureka.client.serviceUrl.defaultZone=http://localhost:20000/eureka/

# 开启Feign下面的Hystrix功能
feign.hystrix.enabled=true
# 是否开启服务降级
hystrix.command.default.fallback.enabled=true

# 全局超时
hystrix.command.default.execution.timeout.enabled=true
# 超时时间 针对全局配置添加超时时间
hystrix.command.default.execution.isolation.thread.timeoutInMilliseconds=1000

# 线程中断行为
# 超时以后终止线程 配置超时行为
hystrix.command.default.execution.isolation.thread.interruptOnTimeout=true

# 取消的时候终止线程
hystrix.command.default.execution.isolation.thread.interruptOnFutureCancel=true

# 针对方法的配置
# Service的类名#方法名(方法参数)
# 方法级别的超时优先级高
hystrix.command.MyService#retry(int).execution.isolation.thread.timeoutInMilliseconds=3000

# 开启访问缓存功能
hystrix.command.default.requestCache.enabled=true


# hystrix的超时与ribbon的超时会有冲突
# 每台机器最大重试次数
feign-client.ribbon.MaxAutoRetries=0
# 可以再重试几台机器
feign-client.ribbon.MaxAutoRetriesNextServer=0
# 连接超时
feign-client.ribbon.ConnectTimeout=1000
# 业务处理超时
feign-client.ribbon.ReadTimeout=8000
# 在所有HTTP Method进行重试
feign-client.ribbon.OkToRetryOnAllOperations=false


```



![](https://tcs.teambition.net/storage/3121ba222c3503cb93cbcc24db9a28b29b02?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUyOCwiaWF0IjoxNjExNDY1NzI4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiYTIyMmMzNTAzY2I5M2NiY2MyNGRiOWEyOGIyOWIwMiJ9.2ufISBWsOp2-wEGHWhGPcBlz5vCCL3ciN4hfD2fOvFs&download=image.png "")

```java
package com.imooc.springcloud;

import com.imooc.springcloud.hystrix.RequestCacheService;
import com.netflix.hystrix.strategy.concurrency.HystrixRequestContext;
import lombok.Cleanup;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;


@RestController
public class Controller {

    @Autowired
    private MyService myService;

    @Autowired
    private RequestCacheService requestCacheService;

    @GetMapping("/fallback")
    public String fallback() {
        return myService.error();
    }

    @GetMapping("/timeout")
    public String timeout(Integer timeout) {
        return myService.retry(timeout);
    }

    @GetMapping("/cache")
    public Friend cache(String name) {

        @Cleanup HystrixRequestContext context =
                HystrixRequestContext.initializeContext();

        Friend friend = requestCacheService.requestCache(name);
        name += "!";
        friend = requestCacheService.requestCache(name);
        return friend;



    }


}

```

![](https://tcs.teambition.net/storage/3121e892c1b29284b63b8def7cb6f0bcb2c3?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUyOCwiaWF0IjoxNjExNDY1NzI4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlODkyYzFiMjkyODRiNjNiOGRlZjdjYjZmMGJjYjJjMyJ9.wgW914nt4WOTdMTbVM2NtxEd46n7WX-6yWKrHSlT6Q0&download=image.png "")

```java
package com.imooc.springcloud.hystrix;

import com.imooc.springcloud.Friend;
import com.imooc.springcloud.MyService;
import com.netflix.hystrix.contrib.javanica.annotation.HystrixCommand;
import com.netflix.hystrix.contrib.javanica.cache.annotation.CacheKey;
import com.netflix.hystrix.contrib.javanica.cache.annotation.CacheResult;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;


@Slf4j
@Service
public class RequestCacheService {

    @Autowired
    private MyService service;

    @CacheResult
    @HystrixCommand(commandKey = "cacheKey")
    public Friend requestCache(@CacheKey String name) {
        log.info("request cache " + name);
        Friend friend = new Friend();
        friend.setName(name);
        friend = service.sayHiPost(friend);
        log.info("after requesting cache " + name);
        return friend;
    }

}

```

![](https://tcs.teambition.net/storage/312143300681b112ef3199e647d4005ac4eb?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUyOCwiaWF0IjoxNjExNDY1NzI4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0MzMwMDY4MWIxMTJlZjMxOTllNjQ3ZDQwMDVhYzRlYiJ9.Stgj-E-Z2JVexUCLS0oVZKXzEl9_K-xjvdCR7y16KSw&download=image.png "")

```java
package com.imooc.springcloud.hystrix;

import com.imooc.springcloud.Friend;
import com.imooc.springcloud.MyService;
import lombok.extern.slf4j.Slf4j;
import org.springframework.stereotype.Component;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestParam;

/**
 * Fallback 针对MyService容错类
 */
@Slf4j
@Component
public class Fallback implements MyService {

    /**
     * 回调降级方法
     * @return
     */
    @Override
    public String error() {
        log.info("Fallback：I'm not a black sheep any more");
        return "Fallback：I'm not a black sheep any more";
    }

    @Override
    public String sayHi() {
        return null;
    }

    @Override
    public Friend sayHiPost(@RequestBody Friend friend) {
        return null;
    }

    @Override
    public String retry(@RequestParam(name="timeout") int timeout) {
        return "You are late !";
    }

}

```

![](https://tcs.teambition.net/storage/3121ab31d9251d3facfcd6007d1142071413?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUyOCwiaWF0IjoxNjExNDY1NzI4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhYjMxZDkyNTFkM2ZhY2ZjZDYwMDdkMTE0MjA3MTQxMyJ9.GayAa6DX9qVCxEDbf49eKqm9MskNdkuOzflAl4JwI7w&download=image.png "")

```java
package com.imooc.springcloud;

import org.springframework.boot.WebApplicationType;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.builder.SpringApplicationBuilder;
import org.springframework.cloud.client.circuitbreaker.EnableCircuitBreaker;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;
import org.springframework.cloud.openfeign.EnableFeignClients;


@EnableDiscoveryClient
@SpringBootApplication
@EnableFeignClients
@EnableCircuitBreaker // 开启断路器
public class HystrixFallbackApplication {

    public static void main(String[] args) throws NoSuchMethodException {
        new SpringApplicationBuilder(HystrixFallbackApplication.class)
                .web(WebApplicationType.SERVLET)
                .run(args);
        /**
         * 生成方法签名
         * int 也可以class
         */
//        System.out.println(Feign.configKey(MyService.class,
//                MyService.class.getMethod("retry", int.class)));
    }

}

```

![](https://tcs.teambition.net/storage/3121ec22985adfee24a9d3446e22c3b7c6b4?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUyOCwiaWF0IjoxNjExNDY1NzI4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlYzIyOTg1YWRmZWUyNGE5ZDM0NDZlMjJjM2I3YzZiNCJ9.1JcfTPr_CXEP8zYYojoSaic9TIjyB42oxqxS7jBtowU&download=image.png "")

```java
package com.imooc.springcloud;

import com.imooc.springcloud.hystrix.Fallback;
import org.springframework.cloud.openfeign.FeignClient;

/**
 * fallback  指定一个类来处理降级异常
 * MyService会将用户请求重新导到了当前Fallback类中 error方法
 */
@FeignClient(name = "feign-client", fallback = Fallback.class)
public interface MyService extends IService {

}

```

![](https://tcs.teambition.net/storage/3121bddd40a6ad3b5db446b153268ffd6793?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUyOCwiaWF0IjoxNjExNDY1NzI4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiZGRkNDBhNmFkM2I1ZGI0NDZiMTUzMjY4ZmZkNjc5MyJ9.XMlOfvZJruo46hKYboy1ql908eGsErfhN1qf1LceKUw&download=image.png "")

```xml
<?xml version="1.0" encoding="UTF-8"?>
<project xmlns="http://maven.apache.org/POM/4.0.0"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
    <parent>
        <artifactId>spring-cloud-demo</artifactId>
        <groupId>com.imooc</groupId>
        <version>1.0-SNAPSHOT</version>
        <relativePath>../../pom.xml</relativePath>
    </parent>
    <modelVersion>4.0.0</modelVersion>
    <packaging>jar</packaging>
    <artifactId>hystrix-fallback</artifactId>

    <dependencies>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-netflix-eureka-client</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-web</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-actuator</artifactId>
        </dependency>

        <dependency>
            <groupId>com.imooc</groupId>
            <artifactId>feign-client-intf</artifactId>
            <version>${project.version}</version>
        </dependency>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-netflix-hystrix</artifactId>
        </dependency>
    </dependencies>

</project>
```

开源笔记

可 Pull Requests 协作写开源笔记

如果笔记图片无法访问 请访问 [teambition](https://tburl.in/0jDNvpbK) 原版开源笔记

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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUyOCwiaWF0IjoxNjExNDY1NzI4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.Q6upjk2bN65fDqcpuRqsSlP5-nJPPMTrItgUwNCW3Rk&download=image.png "")

