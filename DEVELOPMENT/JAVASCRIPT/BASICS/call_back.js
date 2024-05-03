function squares(x){
    return x*x;
}

function cube(x){
    return x*x*x;
}

function sum(a,b,callback){
    console.log(callback(a)+callback(b));
}

sum(2,3,squares);

sum(2,3,cube);

//Output:
//13
//35
