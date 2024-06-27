const mongoose = require('mongoose');
const { number } = require('zod');

// Connect to MongoDB
mongoose.connect('mongodb+srv://souravtechx98:Saurav%402305@cluster0.drxeamg.mongodb.net/');

// Define schemas
const AdminSchema = new mongoose.Schema({
    Adminname:{
        type: String,
        required: true
    },
    password:{
        type: String,
        required: true
    }
});

const UserSchema = new mongoose.Schema({
    Username:{
        type: String,
        required: true
    },
    password:{
        type: String,
        required: true
    },
    purchasedCourses:[{
        type: mongoose.Schema.Types.ObjectId,
        ref: 'Course'
    }]
});

const CourseSchema = new mongoose.Schema({
    coursename:{
        type: String,
        required: true
    },
    duration:{
        type: Number,
        required: true
    },
    price:{
        type: Number,
        required: true
    },
    AdminId:{
        type: mongoose.Schema.Types.ObjectId,//this is the id of the admin who created the course
        ref: 'Admin',
        required: true
    }
});

const Admin = mongoose.model('Admin', AdminSchema);
const User = mongoose.model('User', UserSchema);
const Course = mongoose.model('Course', CourseSchema);

module.exports = {
    Admin,
    User,
    Course
}