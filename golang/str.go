package main
import (
		"fmt"
		)
func main(){
	/*the first is array*/
	var st =[3] string{"fdsf","sdf","dsf"}
	for i := 0;i<3;i++{
		fmt.Printf("%s\n",st[i])
	}

	/*the next is piont*/
	var p *int32
	var ps * string
	fmt.Printf("%d\n",p)
	fmt.Printf("%s\n",ps)
	//if it will be segment fault in C language,but it is true in golang

	/*the next is array of piont*/
	const INDEX int = 4
	var s  [INDEX] *string
	a := [4]string{"he","gert","hret","retert"}
	for i := 0;i<4;i++{
		fmt.Printf("%s\n",a[i])
		s[i] = &a[i]
		fmt.Printf("%s\n",*s[i])
		
	}
	/*the next is diffrent of c and golang
		1.init the array of piont it will be forbidden in golang if it exist the 
		follow sentence,:
		  var str = [4]*string{"ffd","fdg","GDF","DGF"}
		2.output the value ,it must add "*" at before stf[i],it like as *str[i].
		  but in c language ,it is opposited with golang.it need not "*"
	 */

	var cbig city
	var  csmall  city
	cbig =city{"nanjing",455,020}
	csmall =city{"jingzhou",55,5450}
	fmt.Printf("%s\n",cbig.cname)
	fmt.Printf("%d\n",csmall.cid)

	prin(cbig)
	prin(csmall)

	var  cc  *city
	cc = &cbig
	prinf(cc)

	/*the slice func*/	
	num := []int{6,7,7,8,5,4,5,2}
	for i := range num{
		fmt.Printf("the num%d = %d\n",i,num[i])
		
	}
	/*the next is k-v*/
	var idmap map[int]int
	idmap = make(map[int]int)
	idmap[1] = 6
	idmap[2] = 8
	idmap[3] = 10

	for id := range idmap{
	
		fmt.Println("the value of the id",id, "is",idmap[id])
	}
	delete(idmap,1)

	for id := range idmap{
	
		fmt.Println("after delete,the value of the id",id, "is",idmap[id])
	}

	/*the next is recursion*/
	var i int
	i=fib(100)
	fmt.Printf("%d\n",i)
	
	for i=1;i<=100;i++{
		fmt.Printf("%d\t",fib(i))
		if(i%10==0&&i!=0){
		fmt.Printf("\n")
		
		}
	
	}


	/*the next is type change to other type*/
	var ii int = 8
	var ji int = 2
	var m float32 = float32(ii)/float32(ji)

	fmt.Printf("%f\t\n",m)

}
	/*the follow is struct type*/
	type city struct{
		 cname string
		 carea float32
		 cid   int32
	}


func  prin(c city){
	
	fmt.Printf("%s\t",c.cname)
	fmt.Printf("%f\t",c.carea)
	fmt.Printf("%d\n",c.cid)

}
func  prinf(c *city){
	
	fmt.Printf("%s\t",c.cname)
	fmt.Printf("%f\t",c.carea)
	fmt.Printf("%d\n",c.cid)


}

func fib(i int) int{
	if(i==0){
	return 0
	}
	return i+fib(i-1)

}
