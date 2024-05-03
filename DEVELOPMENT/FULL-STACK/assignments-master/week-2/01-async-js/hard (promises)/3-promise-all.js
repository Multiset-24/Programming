/*
 * Write 3 different functions that return promises that resolve after t1, t2, and t3 seconds respectively.
 * Write a function that uses the 3 functions to wait for all 3 promises to resolve using Promise.all,
 * Return a promise.all which return the time in milliseconds it takes to complete the entire operation.
 */

function wait1(t) {
    return Promise((resolve, reject) => {
        setTimeout(() => {
            resolve();
        }, t);
    }
    )
}

function wait2(t) {

    return Promise((resolve, reject) => {
        setTimeout(() => {
            resolve();
        }, t);
    }
    )
}

function wait3(t) {
    return Promise((resolve, reject) => {
        setTimeout(() => {
            resolve();
        }, t);
    }
    )
}

function calculateTime(t1, t2, t3) {
    let start = Date.now();
    return Promise.all([wait1(t1), wait2(t2), wait3(t3)]).then(() => {
        return Date.now() - start;
    })
}

//promises definition- The Promise object represents the eventual completion (or failure) of an asynchronous operation and its resulting value.
// A Promise is a proxy for a value not necessarily known when the promise is created. It allows you to associate handlers with an asynchronous action's eventual success value or failure reason.
module.exports = calculateTime;
