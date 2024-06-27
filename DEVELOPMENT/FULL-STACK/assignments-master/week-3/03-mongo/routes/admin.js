const { Router } = require("express");
const adminMiddleware = require("../middleware/admin");
const router = Router();
const { Admin, Course } = require("../db");

app.use(express.json());
// Admin Routes
router.post('/signup', (req, res) => {
    const AdminName = req.body.AdminName;
    const password = req.body.password;

   const exist= Admin.findOne({
        AdminName:AdminName,
        password:password
    })
    if(exist){
        res.status(403).json({
            msg:"Admin already exists"
        })
    }
    else{
        Admin.create({
            AdminName:AdminName,
            password:password
        })
        res.json({
            msg:"Admin created successfully"
        })
    }
});

router.post('/courses', adminMiddleware, (req, res) => {
    // Implement course creation logic
    const title = req.body.title;
    const duration=req.body.duration;
    const price=req.body.price;
    const AdminId=req.body.AdminId;

    const exist=Course.findOne({
        title:title
    })

    if(exist){
        res.status(403).json({
            msg:"Course already exists"
        })
    }
    else{
        Course.create({
            coursename:title,
            duration:duration,
            price:price,
            AdminId:AdminId
        })
        res.json({
            msg:"Course created successfully"
        })
    }
});

router.get('/courses', adminMiddleware, (req, res) => {
    // Implement fetching all courses logic
    Course.find()
    .then(function(value){
        res.json(value)
    }).catch(function(err){
        res.json({
            msg:"error"
        })
    })
});

module.exports = router;