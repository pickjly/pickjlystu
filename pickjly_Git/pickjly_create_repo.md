# step 1
	在 `github` 官网点击右上角头像，选择 `settings`， 继续选择 `developer settings`， 点击 `Personal access tokens` 
	
# step 2
	生成 `tokens` 之后，复制并保存到本地
	
# step 3
	在终端创建 `repo`:
	curl -u 'pickjly:e878383f668f0e5545ffbc5a166055b547b65b73' https://api.github.com/user/repos -d '{"name":"pickjlystu"}'

# step 4
	在初始化本地仓库之后，关联远程仓库
	git remote add origin https://github.com/pickjly/pickjlystu.git

# step 5
	git push -u origin master