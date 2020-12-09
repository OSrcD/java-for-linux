<template>
  <div id="app">
    <router-view></router-view>
  </div>
</template>

<script>
  export default {
    name: 'App'
  }
  
</script>

<style>
  /* CSS */
  

   
  body,html,#app{
    margin: 0;
    padding: 0;
    height: 100%;
    width: 100%;
    background-color: black;
  }
  ::-webkit-scrollbar{
    display: none;
  }
</style>
