import Vue from 'vue'
import Router from 'vue-router'

Vue.use(Router)

export default new Router({
  routes: [
    {
      path: '/',
      name: 'Terminal',
      component: require('@/components/Terminal').default
    },
    {
      path: '*',
      redirect: '/'
    }
  ]
})
