![](https://tcs.teambition.net/storage/3121b3d3c2819f2f3a460a5e9078ca620fa1?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMDgxMTk3OCwiaWF0IjoxNjEwMjA3MTc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiM2QzYzI4MTlmMmYzYTQ2MGE1ZTkwNzhjYTYyMGZhMSJ9.2ZHnq1_HZEGl-Vguq7Tu2gwpLgB1PjPheton3ur4Btg&download=image.png "")

```javascript
searchInBackend(keywords, sort, page, pageSize) {
					// debugger;
					var serverUrl = app.serverUrl;
					axios.defaults.withCredentials = true;

					// var searchHost = serverUrl + '/items/search?keywords=' + keywords + "&sort=" + sort + "&page=" + page + "&pageSize=" + pageSize;
					var searchHost = 'http://localhost:8033/items/es/search?keywords=' + keywords + "&sort=" + sort + "&page=" + page + "&pageSize=" + pageSize;
					axios.get(searchHost, {})
						.then(res => {
							if (res.data.status == 200) {
								var grid = res.data.data;
								var itemsList = grid.rows;
								this.itemsList = itemsList;

								var maxPage = grid.total;		// 获得总页数
								var total = grid.records;		// 获得总记录数
								
								this.maxPage = maxPage;
								this.total = total;

								// console.log(itemsList);
							} else if (res.data.status == 500) {
								alert(res.data.msg);
								return;
							}
						});
				}


```

![](https://tcs.teambition.net/storage/31212ede501e47d4956b014c9386d17c3d83?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMDgxMjEzOCwiaWF0IjoxNjEwMjA3MzM4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyZWRlNTAxZTQ3ZDQ5NTZiMDE0YzkzODZkMTdjM2Q4MyJ9.CojU2XB2BHs4SBRRsvley2bDnWDyQECq1SoYN6FDfdA&download=image.png "")

![](https://tcs.teambition.net/storage/3121d6b20349ac77828d4765838c5804adb2?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMDgxMjA2NywiaWF0IjoxNjEwMjA3MjY3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkNmIyMDM0OWFjNzc4MjhkNDc2NTgzOGM1ODA0YWRiMiJ9.Wkj05E5-f9Akqz13doQGwQLpvy0WTns2busYHLChWy0&download=image.png "")

![](https://tcs.teambition.net/storage/3121edd60f66793250497f56dd7c218323a7?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMDgxMjIzOCwiaWF0IjoxNjEwMjA3NDM4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlZGQ2MGY2Njc5MzI1MDQ5N2Y1NmRkN2MyMTgzMjNhNyJ9.3L5Mv9wHFwM8Pc_vN1w7vGqD0Cf-i_Zrz84L4Sw19X0&download=image.png "")

```html
<!--<p class="title fl">{{item.itemName}}</p>-->
<p class="title fl" v-html="item.itemName"></p>

```

![](https://tcs.teambition.net/storage/312114b0db9b1f59bd024653970c93156d08?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMDgxMjI2MSwiaWF0IjoxNjEwMjA3NDYxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExNGIwZGI5YjFmNTliZDAyNDY1Mzk3MGM5MzE1NmQwOCJ9.OKuFw_Toqh5mkfCqZ9sase9XLKMJwRRn9z_6skn6u9E&download=image.png "")

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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgwOTM1OCwiaWF0IjoxNjEwMjA0NTU4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.12e2TQDUYgDtfWxb4WZB3JUoD2zTMDWol6grFsA5k0M&download=image.png "")

