package main
import "fmt"
func main(){
	var n int32
	var x float32
	var s string
	var c byte
	var flag bool
	var p *string 
	flag = false
	s = "FDG"
	p = &s
	fmt.Println(n)
	fmt.Println(x)
	fmt.Println(s)
	fmt.Println(p)
	fmt.Println(*p)
	fmt.Printf("p is type of %T\n",p)
	fmt.Println(c)
	fmt.Println(flag)
	/*the above is static declare various\n*/

	y := "wer"
	f := 34.243 
	fmt.Println(y)
	fmt.Println(f)
	fmt.Printf("y is type of %T\n",y)
	fmt.Printf("y is type of %T\n",f)
	/*the above is dynamic declare various\n*/


	var a,b,ci ="dsf", 43, true
	fmt.Println(a)
	fmt.Println(b)
	fmt.Println(ci)
	fmt.Printf("y is type of %T\n",a)
	fmt.Printf("y is type of %T\n",b)
	fmt.Printf("y is type of %T\n",ci)

	/*the above is multiply declare various\n*/

	const MAX int =20
	const LEN float32 = 3.434
	z :=10
	va := z*MAX
	fmt.Println(va)
	fmt.Printf("va is type of %T\n",va)

	/*the above is const keywords\n*/

	val := va + z
	fmt.Println(val)
	fmt.Printf("%d\n",val)

	/*the above is add agol\n*/

	if(val == va){

		fmt.Printf("the same\n")
	}else {
		fmt.Printf("the nosame\n")
	}

	if(flag){

		fmt.Printf("the true\n")
	}else
	{
		fmt.Printf("the false\n")

	}
	/*the above is some agol*/

	var inter interface{}
	switch in := inter.(type){
		case nil:
			fmt.Printf("inter is type of %T\n",in)
		case int:
			fmt.Printf("inter is type of %T\n",in)
		default:
			fmt.Printf("inter is type of know\n")

	}


	var a1,b1 chan int
	var i1,i2 int
	select {
		case i1 =<-a1:
			fmt.Printf("a1 <= b1 ",i1,"a1")
		case i2 =<-b1:
			fmt.Printf("b1 <= c1\n",i2,"b1")
		default:
			fmt.Printf("the end is unknow\n")

	}
	/*the switch and select function*/

	for false{
		fmt.Printf("the end is unknow\n")
	}
	for i :=  0;i<10;i++{
		fmt.Printf("the end is know\n")
	}


	var sum int = 0
	var i int = 1
	for i <= 100{
		sum =i+sum
		i++
		if(i>100){
			break;
		}
	}
	fmt.Println(sum)
	/*sum of 1+2+...100*/

	comp(4,4)
	var cc,d = 3,7
	swap(3,7);

	swp(cc,d);
	fmt.Printf("the cc is %d\n",cc)
	fmt.Printf("the d is %d\n",d)
	/*the demo represent the transfer para in line value
	 the value is changed in their func,but they is not change in main func
	 and the transfer para in line address is similar with C,so we don't display
	 */
}
func comp(x,y int) int{
	if(x==y){
		fmt.Printf("the same\n")
		return 0
	}else{
		return  -1
	}
	return 0
}

func swap(a,b int) int{
//	var tmp int
	a+=b
	b=a-b
	a-=b

	fmt.Printf("the a is %d\n",a)
	fmt.Printf("the b is %d\n",b)
	return 0

}


func swp(a,b int) int{
	var tmp int
	tmp = a
	a = b
	b = tmp
//	b=a-b
//	a-=b

	return 0
}
