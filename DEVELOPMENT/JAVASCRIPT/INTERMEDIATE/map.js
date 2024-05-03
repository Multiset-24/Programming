const arr=[1,2,3,4,5,6,7,8,9];  

const newArr=arr.map((value)=>{
    return value*2;
}
)

console.log(newArr);

//create a map function which takes an array and a function as an argument and returns a new array
//in which every value is passed through that function
const map=(arr,func)=>{
    let newarr=[];
    for(let i=0;i<arr.length;i++){
        newarr.push(func(arr[i]));
    }
    return newarr;
}

function double(value){
    return value*2;
}

function triple(value){
    return value*3;
}

console.log(map(arr,triple));



