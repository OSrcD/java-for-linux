

HashSet 无序 不可重复

只能一个 null

良好的存取 查找性能

底层是HashMap

加载因子为 0.75f

容量为16

add(Object) 添加元素

hasNext() 调用这个方法之前指向头指针 

调用之后是检测有没有下一条数据

调用next指向第一条数据，得到数据

![](https://tcs.teambition.net/storage/31233440cdfdf24113972ef411d081a2eccb?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkwNywiaWF0IjoxNjE1NTQ3MTA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjMzNDQwY2RmZGYyNDExMzk3MmVmNDExZDA4MWEyZWNjYiJ9.2tYmXohnU16JDTwoU4tGMpaiYZ3a2h1sd_8vX1Grh5E&download=image.png "")

Iterator it = iterator(); 返回迭代器接口

hasNext();是否有下一个元素

next(); 指向下一个元素并把数据提取出来 输出调用toString方法 查找数据

null元素无法输出 特殊的空类型



重写hashCode equals方法 用于判断对象的内容是否重复



![](https://tcs.teambition.net/storage/3123665eca00dbd04f69140e0e1db70464c6?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkwNywiaWF0IjoxNjE1NTQ3MTA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjM2NjVlY2EwMGRiZDA0ZjY5MTQwZTBlMWRiNzA0NjRjNiJ9.k2joapkUqU65QetsW8ordYoArvuj9fr9ufudjf6Hp3M&download=image.png "")

HashSet 原理

3个 桶 为3个桶编码

正整数 % 3 = 余数

从数学角度思考 余数 一定比 除数小  

余数只能是 0 1 2 

不可能>=3

所以元素会落在这三个桶里面

2%3=2

3%3=0``

4%3=1

三个桶至少提高了三分之二的时间



![](https://tcs.teambition.net/storage/312397a7c304cb1cde98ded40cecd5059380?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkwNywiaWF0IjoxNjE1NTQ3MTA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjM5N2E3YzMwNGNiMWNkZTk4ZGVkNDBjZWNkNTA1OTM4MCJ9.A_E8HxlPIhN4RNxBdb7vr5iji_p4ZKePZzA11v-nL14&download=image.png "")

![](https://tcs.teambition.net/storage/312385ee0b05c54399c1bb15e7731004c5b2?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkwNywiaWF0IjoxNjE1NTQ3MTA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjM4NWVlMGIwNWM1NDM5OWMxYmIxNWU3NzMxMDA0YzViMiJ9.y0VBZeHaXBRYEpNISV185868HjEBVEMWUkZwFnAx364&download=image.png "")

判断元素是在哪个桶是hashCode方法

在桶里面遍历元素用的是equals方法

返回true 就是重复

```java
if(this == obj)
	return true;

if(obj.getClass() == Xx.class){
	Xx xx = (Xx)obj;
	return xx.getXx().equals(this.Xx) && (xx.getXx() == this.Xx));
}

return false;
```



![](https://tcs.teambition.net/storage/3123b9c761286acf8c479c90db08b72a8007?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkwNywiaWF0IjoxNjE1NTQ3MTA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjNiOWM3NjEyODZhY2Y4YzQ3OWM5MGRiMDhiNzJhODAwNyJ9.6u906wXUrEPLRVV76q5oujxBd730J4LsdJMBFaT1tuw&download=image.png "")

String类的 hashCode与equals方法已经设置好了



contains(Object) 查找元素

使用迭代器从头到尾

通过对象属性去查找

增强型for循环HashSet





不加泛型随便强转会不安全

加泛型强制类型转换是隐式进行的，编译器帮我们做了



remove(Object) 删除元素 在最后一个元素删除不会报错 删除了不能再遍历了 可以使用 break;

removeAll(Collection<?>) 从一个集合中删除子集

isEmpty() 判断元素是否为空







HashMap

底层是数组 链表 红黑树

包含一个监听接口 Entry key value 无序排列   实现类是 Node

键不能重复

值可以相同 键不能重复就行

key和value 可以是 null

只能为一个空的键

容量 16 加载因子0.75f



put(Object,Object) 添加元素

values().iterator(); 返回所有value的迭代器接口

hasNext();

next();

entrySet(); 返回Set<Map.Entry<Object,Ojbect>>

Entry.geyKey(); 返回 key

Entry.getValue(); 返回 value

keySet();返回Set<Object> 

查询 get(Object);

key值相同会被保留进添加的

containsKey(Object) 判断key 是否存在



正确处理异常

![](https://tcs.teambition.net/storage/3123c4db1f12f96d32e89d0cf225d842740d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkwNywiaWF0IjoxNjE1NTQ3MTA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjNjNGRiMWYxMmY5NmQzMmU4OWQwY2YyMjVkODQyNzQwZCJ9.wdf6LOg0jLjtWYJxxfIsLYXlocrv9KyWWU81hM4fi8Q&download=image.png "")





Arrays.sort(数组)



Collections.sort(List<T>) 升序

Collections.sort(List<T>,Comparator<? super T>)  < - TT>

字符串会按照ASCII码排序



对象排序

实现Comparator<T>

重写compare(T1,T2)



字符串升序排列

第一个参数在前 第二个参数在后

return T1.compareTo(T2)  字符串实现了Comparable

T1 - T2



降序

第二个参数在前  第一个参数在后

return T2.compareTo(T1) 

T2 - T1



实现Comparable接口

重写compareTo(T)方法

this - T 升序

T - this 降序

直接调用sort方法放入集合就可以了



泛型

为了不用转换 消除安全隐患

![](https://tcs.teambition.net/storage/3123b66b4423f57b119e755d28b47f0c13d1?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkwNywiaWF0IjoxNjE1NTQ3MTA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjNiNjZiNDQyM2Y1N2IxMTllNzU1ZDI4YjQ3ZjBjMTNkMSJ9.RiTyfVB_EoXpxSeNpwvG6mZHQp2T9wptnHvE9cx3HDA&download=image.png "")

![](https://tcs.teambition.net/storage/3123a2f0abb5c6051ec08c54ff167b02ab92?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkwNywiaWF0IjoxNjE1NTQ3MTA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjNhMmYwYWJiNWM2MDUxZWMwOGM1NGZmMTY3YjAyYWI5MiJ9._rLlJOB9vFv5BJvHcfleiEvO56miqtnprVvhhxa9HU8&download=image.png "")

<? extends Goods> <+ Goods> 

<? extends T> <+T T>  表示第一个T 就是用 第二个T来表示  而第二个T就是泛型定义的T:Object

所以就是 <+ Object> 第二个 T 需要根据具体的泛型参数化变动

1. 可以set为null 

1. get 可以获取为 Object 

<? super T> <-TT> <- Object>

1. set 方法可以为null

1. get 方法可以获取为Object

<?> <*> 不知道的泛型类型 编译器不知道什么类型 程序员知道什么类型 

1. 可以set 为null

1. 可以 get 获取为 Object 

<T> < T extends Object> <T : Object>

<T extends Number> <T:Number> 表示 Number类以及子类

加上具体泛型就是参数化了



泛型方法

![](https://tcs.teambition.net/storage/312373618a906e248713f6e312002f2597a9?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkwNywiaWF0IjoxNjE1NTQ3MTA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjM3MzYxOGE5MDZlMjQ4NzEzZjZlMzEyMDAyZjI1OTdhOSJ9.kt94MLiuNVGW_CVQeorlKvvop9SxCO2PGKqLvQfqw6w&download=image.png "")

![](https://tcs.teambition.net/storage/3123f50a78f1dd1df86f11f30d95a25d20da?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkwNywiaWF0IjoxNjE1NTQ3MTA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjNmNTBhNzhmMWRkMWRmODZmMTFmMzBkOTVhMjVkMjBkYSJ9.rTh3zNWkLuyHum5ehyhLh8_YnCcTObhrh20l4aj1wXg&download=image.png "")

泛型方法不支持T super Integer



线程

一个程序可以包含多个进程 多个线程

![](https://tcs.teambition.net/storage/31235000f71312a44ad9b2881d6e9bb2a919?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkwNywiaWF0IjoxNjE1NTQ3MTA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjM1MDAwZjcxMzEyYTQ0YWQ5YjI4ODFkNmU5YmIyYTkxOSJ9.8bpvsiFTEOELM2eHnhHNYk3LSRXZ8W5fMoyOUztWIsU&download=image.png "")

![](https://tcs.teambition.net/storage/3123232020a81ceddb5d8faaab8eeb62c1d7?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkwNywiaWF0IjoxNjE1NTQ3MTA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjMyMzIwMjBhODFjZWRkYjVkOGZhYWFiOGVlYjYyYzFkNyJ9.OsRTGbgwqlhSIr_DLK10LaTsvrKBsePETa_pVd3zHkQ&download=image.png "")

启动线程会去执行run方法的代码体，一个线程只能启动一次 不能多次调用start方法

getName() 获得线程名 

Thread.currentThread().getName();  当前线程对象.获得线程名

线程共享堆对象

不共享栈对象







![](https://tcs.teambition.net/storage/312395af2556fa9b3d69bab4a81880c39ae5?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkwNywiaWF0IjoxNjE1NTQ3MTA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjM5NWFmMjU1NmZhOWIzZDY5YmFiNGE4MTg4MGMzOWFlNSJ9.ojbOm7ju1yu03w9KGJwT5X48gbJazESFe5zCExNYK-s&download=image.png "")

可以调用yield（）从正在运行状态切换到可运行状态，放弃CPU的时间片(不一定有效果，CPU可能还是再次运行调用的yield方法的线程)



sleep()  定时 定期 有误差



join 在当前线程中调用其他线程的join方法 这个线程会暂停或可运行状态 需要等待线程执行完 才能获得时间片继续执行

加入的意思，抢先去执行

 

这个线程优先执行，其他线程进入暂停状态（或者是一个可运行的状态），没有CPU时间片使用权，只有等这个线程结束后，其他线程才能执行



![](https://tcs.teambition.net/storage/3123761b2fe74dac5e55193130131eb40fc5?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkwNywiaWF0IjoxNjE1NTQ3MTA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjM3NjFiMmZlNzRkYWM1ZTU1MTkzMTMwMTMxZWI0MGZjNSJ9.EmGvknlOB_txBmLeSi8X-3A0U2g77zdArNoFEBwdL5s&download=image.png "")

调用join方法线程执行1000ms，不管该线程是否结束，都会把CPU使用权主动权让出来，我都会继续执行其他线程



![](https://tcs.teambition.net/storage/31231902060c7bdf9e05bf3cf7185bff6c62?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkwNywiaWF0IjoxNjE1NTQ3MTA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjMxOTAyMDYwYzdiZGY5ZTA1YmYzY2Y3MTg1YmZmNmM2MiJ9.UKgXQJw3TIhTs9Zmm8LgbJRDdpUKD0xRm4gQEMRa1Pg&download=image.png "")

![](https://tcs.teambition.net/storage/312360aa368fe66ee29f115167c5ad502a48?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkwNywiaWF0IjoxNjE1NTQ3MTA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjM2MGFhMzY4ZmU2NmVlMjlmMTE1MTY3YzVhZDUwMmE0OCJ9.cySViMgyD4SxXhN72pw1l6K1zIaF-9BHXKnkoYAXN5w&download=image.png "")

![](https://tcs.teambition.net/storage/31239906d543a2cd6bc6a67362eace3ae0ea?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkwNywiaWF0IjoxNjE1NTQ3MTA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjM5OTA2ZDU0M2EyY2Q2YmM2YTY3MzYyZWFjZTNhZTBlYSJ9.iug-SHc1ekAr5H5mYOWeYIQvRfAaJgLBsdaTzVeMUQU&download=image.png "")

![](https://tcs.teambition.net/storage/3123b260a073a57c0467e4581a01592fbfd6?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkwNywiaWF0IjoxNjE1NTQ3MTA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjNiMjYwYTA3M2E1N2MwNDY3ZTQ1ODFhMDE1OTJmYmZkNiJ9.gZysfubXW7RnNvzD6jf4EugVUbemN9-vPQdxCeJcIt4&download=image.png "")

![](https://tcs.teambition.net/storage/3123ffd7f15fcfcee1504dba0dcc7ac292d9?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkwNywiaWF0IjoxNjE1NTQ3MTA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjNmZmQ3ZjE1ZmNmY2VlMTUwNGRiYTBkY2M3YWMyOTJkOSJ9.KJIiVLFJQxTpqovV_2R846BtfgpK2N6DFEugzJJKLoU&download=image.png "")

![](https://tcs.teambition.net/storage/312377f717b096af116eb272f48c81b559ff?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkwNywiaWF0IjoxNjE1NTQ3MTA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjM3N2Y3MTdiMDk2YWYxMTZlYjI3MmY0OGM4MWI1NTlmZiJ9.kn6BP4YKMoJyq9tD7wA8X6bsa09wGxyQqiHS3kRqeyU&download=image.png "")

![](https://tcs.teambition.net/storage/3123744d46fa9e8d096f00243d74016ee003?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkwNywiaWF0IjoxNjE1NTQ3MTA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjM3NDRkNDZmYTllOGQwOTZmMDAyNDNkNzQwMTZlZTAwMyJ9.TGySbY8iePweBaXJGTo-1DIN2bsQlDrmrulWxrPOk6E&download=image.png "")

notify只是随机唤醒某一个，两个线程死锁了，生产者生产了，被wait了，可能唤醒的还是生产者线程，还是死锁状态

![](https://tcs.teambition.net/storage/3123245ef3a1152940c0aee48721a4628ec2?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkwNywiaWF0IjoxNjE1NTQ3MTA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjMyNDVlZjNhMTE1Mjk0MGMwYWVlNDg3MjFhNDYyOGVjMiJ9.8W3oeHradIuDSgOXQVYHWOOzLioqPpf5U6U8t5Jyjgs&download=image.png "")

![](https://tcs.teambition.net/storage/3123621066ea9da3fd0722e9416203edf9cc?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkwNywiaWF0IjoxNjE1NTQ3MTA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjM2MjEwNjZlYTlkYTNmZDA3MjJlOTQxNjIwM2VkZjljYyJ9.R7ymJz8eyZWwfnTCUxFlugr-rnW5yrusMj1xjo1Kl60&download=image.png "")





io流

![](https://tcs.teambition.net/storage/31231045502728cf64fd7a94d9df3f769b63?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkwNywiaWF0IjoxNjE1NTQ3MTA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjMxMDQ1NTAyNzI4Y2Y2NGZkN2E5NGQ5ZGYzZjc2OWI2MyJ9.1JPMSabs3Aw7UR_u2TMnnV_GFaUkp_ixl475KNeZ-JE&download=image.png "")

File 类不分文件和目录





全路径一个对象

![](https://tcs.teambition.net/storage/312352fe00743ab4948dfd79b1e0b78a76f5?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkwNywiaWF0IjoxNjE1NTQ3MTA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjM1MmZlMDA3NDNhYjQ5NDhkZmQ3OWIxZTBiNzhhNzZmNSJ9.IxQwc1G7_xtde0sfbaEUZ89a1KUCzZt8FbP7rmNQOP4&download=image.png "")

子路径对象

![](https://tcs.teambition.net/storage/3123e29e73d18168195369e3eedb50864b42?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkwNywiaWF0IjoxNjE1NTQ3MTA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjNlMjllNzNkMTgxNjgxOTUzNjllM2VlZGI1MDg2NGI0MiJ9.miHocP1rnjNgywKNTXvS3L32JXPdjny8zbawuDvQVSA&download=image.png "")

在File的基础上创建一个file

![](https://tcs.teambition.net/storage/3123797bf74b6bb67ed13a4e668c43d84097?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkwNywiaWF0IjoxNjE1NTQ3MTA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjM3OTdiZjc0YjZiYjY3ZWQxM2E0ZTY2OGM0M2Q4NDA5NyJ9.Gnu2WVAeNjqudzcNE8hL8HcPVjuI2gi8bw3iMTFaG7o&download=image.png "")

isDirectory()

isFile()

exists() 可以判断文件也可以判断目录

mkdir()

mkdirs()

createNewFile();

与源文件相同路径是当前路径

绝对路径从盘符开始

../ 上一级目录

./ 当前目录

isAbsolute()

getPath() 获取相对路径

getAbsolutePath() 获取绝对路径

getName() 获取文件名

在源码相对目录默认是工程名的目录







![](https://tcs.teambition.net/storage/31232fbf7fb3d76c877f3d3f8cf22e07851a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkwNywiaWF0IjoxNjE1NTQ3MTA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjMyZmJmN2ZiM2Q3NmM4NzdmM2QzZjhjZjIyZTA3ODUxYSJ9.DN553gGbisLvGrm9wZ4H7ZjKjm2lOHtkiPc-o60ilhk&download=image.png "")

![](https://tcs.teambition.net/storage/312351d1fbd28799226e7018cd0c32d1a230?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkwNywiaWF0IjoxNjE1NTQ3MTA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjM1MWQxZmJkMjg3OTkyMjZlNzAxOGNkMGMzMmQxYTIzMCJ9.eE02gZr5nBYNX1vyVvm9ImrnAmumyaxeT0IB_o7M3uE&download=image.png "")

![](https://tcs.teambition.net/storage/3123843be93ebce9f8db8fc0895a9d25c9e0?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkwNywiaWF0IjoxNjE1NTQ3MTA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjM4NDNiZTkzZWJjZTlmOGRiOGZjMDg5NWE5ZDI1YzllMCJ9.x9gGkqhIQFoPRuFMWm_h3L2kvxT67m-PC8Mx_pSoE78&download=image.png "")

![](https://tcs.teambition.net/storage/3123a57e82119bd1fa367d1a8bab8fcdc4c3?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkwNywiaWF0IjoxNjE1NTQ3MTA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjNhNTdlODIxMTliZDFmYTM2N2QxYThiYWI4ZmNkYzRjMyJ9.y458utgMy69YfuxXb2puv8N1Q0X_y35BElikYANMYe0&download=image.png "")

![](https://tcs.teambition.net/storage/3123837b2f09b6df90b60ac12c54ba9688b3?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkwNywiaWF0IjoxNjE1NTQ3MTA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjM4MzdiMmYwOWI2ZGY5MGI2MGFjMTJjNTRiYTk2ODhiMyJ9.QDKHs4b8EErr68nZz2dz5_nXjUsRj2AaCuE-24vYEiU&download=image.png "")

![](https://tcs.teambition.net/storage/31232d81e6270ff3cfa08572eb3938229911?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkwNywiaWF0IjoxNjE1NTQ3MTA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjMyZDgxZTYyNzBmZjNjZmEwODU3MmViMzkzODIyOTkxMSJ9.9OY5r3fpN3wSA8iV1tZlQSZDdnFQhJoUKHZsXZRsYI8&download=image.png "")



InputStream 字节输入流父类

OutputStream 字节输出流父类



FileInputStream 文件输入流 不适合字符 适合二进制

New FileInputStream(String)

read() 返回值为读取数据

close()

read(byte[],int,int) 从byte[] 数组 那个位置开始存数据 存多少个长度

read(byte[])



FileOutputStream 文件输出流

New FileOutputStream(String)

write(int)

write(byte[])

write(byte[],int,int)

close()



BufferedInputStream 缓冲输入流

new BufferedInpuStream(InputStream)

read(int)

read(byte[])

read(byte[],int,int)

close()





BufferedOutputStream 缓冲输出流

new BufferedOutputStream(OutputStream)

write(int) 写到缓冲区当中

wrte(byte[])

write(byte[],int,int)

flush()从缓冲区写到文件当中

close()



Reader 字符输入流父类

Write 字符输出流父类



InputStreamReader 字节字符输入转换流

new InputStreamReader(InputStream)

new InputStreamReader(InputStream,String charset)

read(char[],int,int)

read() 返回一个int

new String(char[])

new String(char[],int,int)

close()





OutputStreamWriter 字节字符输出转换流

new OutputStreamWriter(OutputStream,String charset)

write(int)

write(String,int,int)

write(char[],int,int)

flush() 强制清空缓冲区内容

close()









BufferedReader 字符缓冲输入流

new BufferdReader(Reader)

read()

read(char[],int,int)

close();



BufferedWriter 字符缓冲输出流

new BufferedWriter(Writer)

write(int)

write(char[],int,int)

write(String,int.int)

flush()

close()



FileReader 文件字符流 用于从文件当中以字符的方式读取

File 文件目录流



继承 Serializable

读和写的顺序要一样





ObjectInputStream 对象输入流

new ObjectInputStream(InputStream)

readObject();

close()





ObjectOutputStream 对象输出流

new ObjectOutputStream(OutputStream)

writeObject(Object)

writeBoolean(boolean)

flush()

close()





System.currentTimeMillis() 当前时间减去1970-1-1基准时间而得到的一个长整形的数据









Tomcat 目录结构

bin 目录可执行  文件 shutdown.sh startup.sh

lib 依赖的jar包文件

logs 日志目录 catalina.out

config 配置文件目录 Server.xml 配置端口    context.xml 配置cookie

work 目录 存放jsp 编译为Servlet的class文件 

webapps 存放开发者的war包

temp 临时文件目录

![](https://tcs.teambition.net/storage/3123043670765b1b63f091b355c8209ad2a9?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkwNywiaWF0IjoxNjE1NTQ3MTA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjMwNDM2NzA3NjViMWI2M2YwOTFiMzU1YzgyMDlhZDJhOSJ9.t6-srMBZmaiiZz8QgdJHUCVWJ8e-gn0jkrJnSkVHWHE&download=image.png "")



![](https://tcs.teambition.net/storage/312306ccb85b96a1ea6ab34996ea337c96d2?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkwNywiaWF0IjoxNjE1NTQ3MTA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjMwNmNjYjg1Yjk2YTFlYTZhYjM0OTk2ZWEzMzdjOTZkMiJ9.tq8oONUk_3wQB31AYAcj2mi4XmZhoGBVY-rlks2mprA&download=image.png "")

lib 目录是放置依赖的jar包文件

![](https://tcs.teambition.net/storage/31236fc6a4b4cf28b8ce6404d0343cc36f41?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkwNywiaWF0IjoxNjE1NTQ3MTA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjM2ZmM2YTRiNGNmMjhiOGNlNjQwNGQwMzQzY2MzNmY0MSJ9.2TJcBQt4KHxbJeGgE_2PV6A9YeGrl8hbYZngJXEYGrw&download=image.png "")











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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkwNywiaWF0IjoxNjE1NTQ3MTA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.7cwYF_cmzf2F5KPuw9CvMWVWoVIsBmPbgbo1iYfmix4&download=image.png "")

