import React from 'react'
import Header from '../Components/Header/header.jsx'
import {Footer} from '../Components/Footer/footer.jsx'
import { Outlet } from 'react-router-dom'

function Layout() {
  return (
    <>
    <Header/>
    <Outlet />
    <Footer />
    </>
  )
}

export default Layout