//synchronous and asynchrounous functions

function findsum(n){
    let ans=0;

    for(let i=0;i<=n;i++){
        ans+=i;
    }
     return ans;
}


function findSumTill100(){
    console.log(findsum(100));
}

setTimeout(findSumTill100,500);

console.log("hello world ");


function findSumTill200(){
    console.log(findsum(200));
}

setTimeout(findSumTill200,1000);// one of the async functions


//another function  is fs.readFile and  fetch functions

