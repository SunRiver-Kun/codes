--Print(1,"string",true,nil)
Print("当前时间为：",nowtime())

--local 的无法识别到
str = "add(a:number,b:number) -> number"
function add(a,b)
    return a+b
end
