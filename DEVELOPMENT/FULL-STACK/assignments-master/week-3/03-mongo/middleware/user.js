const { User } = require('../db/index.js');

function userMiddleware(req, res, next) {
    // Implement user auth logic
    // You need to check the headers and validate the user from the user DB. Check readme for the exact headers to be expected
    const UserName=req.headers.UserName;
    const password=req.headers.password;

    User.findOne({
        UserName:UserName,
        password:password
    })
    .then(function(value){
        if(value){
            next();
        }
        else{
            res.status(403).json({
                msg:"User doesnt exist"
            })
        }
    }
    )
}

module.exports = userMiddleware;