import Vue from 'vue'
import Router from 'vue-router'
import Index from '@/components/Index'   // add
import Archive from '@/components/Archive'   // add
import Contact from '@/components/Contact'   // add
import Single from '@/components/Single'   // add
import Admin from '@/components/Admin'   // add
import Login from '@/components/Login'   // add

Vue.use(Router)

export default new Router({
  routes: [
    {
      path: '/Index',
      name: 'Index',
      component: Index
    },
    {
      path: '/Archive',
      name: 'Archive',
      component: Archive
    },
    {
      path: '/Contact',
      name: 'Contact',
      component: Contact
    },
    {
      path: '/Single',
      name: 'Single',
      component: Single
    },
    {
      path: '/Admin',
      name: 'Admin',
      component: Admin
    },
    {
      path: '/Login',
      name: 'Login',
      component: Login
    }
  ]
})
