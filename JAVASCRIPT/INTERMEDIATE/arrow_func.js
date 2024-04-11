//arrow ,map,filter,reduce

//given an array ,give me back a new array in which every value is multiplied by 2

const arr = [1, 2, 3, 4, 5, 6, 7, 8, 9];

const newArr=(arr)=>{
    for(let i=0;i<arr.length;i++){
        arr[i]=arr[i]*2;
    }
    return arr;
}

console.log(arr);