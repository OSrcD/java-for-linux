<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>

<%
  String user = (String)session.getAttribute("loginUser");
%>
<!DOCTYPE html>
<html>
<head>
<title>Peculiar a Personal Portfolio Flat Bootstarp responsive Website Template| HOME :: w3layouts</title>
<meta name="viewport" content="width=device-width, initial-scale=1">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<meta name="keywords" content="Peculiar Responsive web template, Bootstrap Web Templates, Flat Web Templates, Andriod Compatible web template, 
Smartphone Compatible web template, free webdesigns for Nokia, Samsung, LG, SonyErricsson, Motorola web design" />
<script type="application/x-javascript"> addEventListener("load", function() { setTimeout(hideURLbar, 0); }, false); function hideURLbar(){ window.scrollTo(0,1); } </script>
<link href="css/bootstrap.css" rel='stylesheet' type='text/css' />
<link href="css/style.css" rel='stylesheet' type='text/css' />
<script src="js/jquery-1.11.0.min.js"></script>
<!---- start-smoth-scrolling---->
<script type="text/javascript" src="js/move-top.js"></script>
<script type="text/javascript" src="js/easing.js"></script>
<script type="text/javascript">
			jQuery(document).ready(function($) {
				$(".scroll").click(function(event){		
					event.preventDefault();
					$('html,body').animate({scrollTop:$(this.hash).offset().top},1000);
				});
			});
		</script>

<!--start-smoth-scrolling-->
<!--animated-css-->
		<link href="css/animate.css" rel="stylesheet" type="text/css" media="all">
		<script src="js/wow.min.js"></script>
		<script>
		 new WOW().init();
		</script>
<!--animated-css-->  
</head>
<body>
	<!--start-banner-->
		<div class="banner" id="home">
			<div  id="top" class="callbacks_container">
			     <ul class="rslides" id="slider4">
			       <li>
	    				<div class="banner-1">
						</div>
					</li>
					 <li>
	    				<div class="banner-2">
						</div>
					</li>
			     </ul>
			</div>
			<div class="clearfix"> </div>
			<div class="header">
				<div class="navigation">
				 <span class="menu"></span> 
					<ul class="navig">
					    <li><a href="index.html" class="scroll"><%=user  %></a><span>|</span></li>
						<li><a href="index.html" class="scroll">HOME</a><span>|</span></li>
						<li><a href="#portfolio" class="scroll">PORTFOLIO</a><span>|</span></li>
						<li><a href="#contact" class="scroll">CONTACT</a></li>
					</ul>
				</div>
				<div class="clearfix"></div>
			</div>
			<div class="banner-bottom">
				<ul>
					<li><a href="#"><span class="twt"> </span></a></li>
					<li><a href="#"><span class="t"> </span></a></li>
					<li><a href="#"><span class="g"> </span></a></li>
				</ul>
			</div>
		</div>	
	<!-- script-for-menu -->
		 <script>
				$("span.menu").click(function(){
					$(" ul.navig").slideToggle("slow" , function(){
					});
				});
		 </script>
		 <!-- script-for-menu -->
		<!--Slider-Starts-Here-->
				<script src="js/responsiveslides.min.js"></script>
			 <script>
			    // You can also use "$(window).load(function() {"
			    $(function () {
			      // Slideshow 4
			      $("#slider4").responsiveSlides({
			        auto: true,
			        pager: false,
			        nav: true,
			        speed: 500,
			        namespace: "callbacks",
			        before: function () {
			          $('.events').append("<li>before event fired.</li>");
			        },
			        after: function () {
			          $('.events').append("<li>after event fired.</li>");
			        }
			      });
			
			    });
			  </script>
			<!--End-slider-script-->
	<!--end-banner-->	
	<!--start-free-->	 
	<div class="free wow bounce" data-wow-delay="0.1s">
		<div class="container">
			<div class="free-main">
				<h1>PROIN CONVALLIS SED FELIS EU MALESUADA</h1>
				<p><sup><img src="images/quote-1.png" alt=""></sup> Etiam in porttitor risus. Curabitur non diam id lacus facilisis consequat. Integer pulvinar ex nunc, id porttitor orci sollicitudin id. Morbi vitae sodales arcu, vel maximus neque. Nullam a faucibus justo sit. <sub><img src="images/quote-2.png" alt=""></sub> </p>
			</div>
		</div>
	</div>
	<!--end-free-->	 
	<!-- Portfolio Starts Here -->
	<div class="portfolios entertain_box  wow fadeInUp" data-wow-delay="0.4s" id="portfolio">
		<div class="container">
			<div class="portfolio-top">
			<ul id="filters" class="clearfix">
						<li><span class="filter active" data-filter="app card icon logo web">All Portfolio</span></li>
						<li><span class="filter" data-filter="app">Web Development</span></li>
						<li><span class="filter" data-filter="photo">Mockups</span></li>
						<li><span class="filter" data-filter="card">Scripts</span></li>
					</ul>
					<div id="portfoliolist">
					<div class="portfolio app mix_all" data-cat="app" style="display: inline-block; opacity: 1;">
						<div class="portfolio-wrapper">		
							<a href="images/p-1.jpg" class="b-link-stripe b-animate-go   swipebox"  title="Image Title">
						     <img src="images/port-1.jpg" /><div class="b-wrapper"><h2 class="b-animate b-from-left    b-delay03 ">
						     	<ul>
						     		<li><img src="images/hrt.png" alt=""/></li>
						     		<li><img src="images/srch.png" alt=""/></li>
						     		<li><img src="images/rsh.png" alt=""/></li>
						     	</ul>
						     	</h2>
						  	 </div></a>
		                </div>
					</div>				
					<div class="portfolio card mix_all" data-cat="card" style="display: inline-block; opacity: 1;">
						<div class="portfolio-wrapper">		
							<a href="images/p-2.jpg" class="b-link-stripe b-animate-go   swipebox"  title="Image Title">
						     <img src="images/port-2.jpg" /><div class="b-wrapper"><h2 class="b-animate b-from-left    b-delay03 ">
						     	<ul>
						     		<li><img src="images/hrt.png" alt=""/></li>
						     		<li><img src="images/srch.png" alt=""/></li>
						     		<li><img src="images/rsh.png" alt=""/></li>
						     	</ul>
						     	</h2>
						  	 </div></a>
		               </div>
					</div>		
					<div class="portfolio photo mix_all" data-cat="photo" style="display: inline-block; opacity: 1;">
						<div class="portfolio-wrapper">		
							<a href="images/p-3.jpg" class="b-link-stripe b-animate-go   swipebox"  title="Image Title">
						     <img src="images/port-3.jpg" /><div class="b-wrapper"><h2 class="b-animate b-from-left    b-delay03 ">
						     	<ul>
						     		<li><img src="images/hrt.png" alt=""/></li>
						     		<li><img src="images/srch.png" alt=""/></li>
						     		<li><img src="images/rsh.png" alt=""/></li>
						     	</ul>
						     	</h2>
						  	 </div></a>
		                </div>
					</div>				
					<div class="portfolio card mix_all" data-cat="card" style="display: inline-block; opacity: 1;">
						<div class="portfolio-wrapper">		
							<a href="images/p-4.jpg" class="b-link-stripe b-animate-go   swipebox"  title="Image Title">
						     <img src="images/port-4.jpg" /><div class="b-wrapper"><h2 class="b-animate b-from-left    b-delay03 ">
						     <ul>
						     		<li><img src="images/hrt.png" alt=""/></li>
						     		<li><img src="images/srch.png" alt=""/></li>
						     		<li><img src="images/rsh.png" alt=""/></li>
						     	</ul>
						     	</h2>
						  	 </div></a>
		                </div>
		               
					</div>	
					<div class="portfolio photo mix_all" data-cat="photo" style="display: inline-block; opacity: 1;">
						<div class="portfolio-wrapper">		
							<a href="images/p-5.jpg" class="b-link-stripe b-animate-go   swipebox"  title="Image Title">
						     <img src="images/port-5.jpg" /><div class="b-wrapper"><h2 class="b-animate b-from-left    b-delay03 ">
						     	<ul>
						     		<li><img src="images/hrt.png" alt=""/></li>
						     		<li><img src="images/srch.png" alt=""/></li>
						     		<li><img src="images/rsh.png" alt=""/></li>
						     	</ul>
						     	</h2>
						  	 </div></a>
		                </div>
		               
					</div>			
					<div class="portfolio app mix_all" data-cat="app" style="display: inline-block; opacity: 1;">
						<div class="portfolio-wrapper">		
							<a href="images/p-6.jpg" class="b-link-stripe b-animate-go  swipebox"  title="Image Title">
						     <img src="images/port-6.jpg" /><div class="b-wrapper"><h2 class="b-animate b-from-left    b-delay03 ">
						     	<ul>
						     		<li><img src="images/hrt.png" alt=""/></li>
						     		<li><img src="images/srch.png" alt=""/></li>
						     		<li><img src="images/rsh.png" alt=""/></li>
						     	</ul>
						     	</h2>
						     	
						  	 </div></a>
		                </div>
		                
					</div>		
		</div>
		</div>
	</div>
</div>
<link rel="stylesheet" href="css/swipebox.css">
	<script src="js/jquery.swipebox.min.js"></script> 
	    <script type="text/javascript">
			jQuery(function($) {
				$(".swipebox").swipebox();
			});
		</script>
	<!-- Portfolio Ends Here -->
	<script type="text/javascript" src="js/jquery.mixitup.min.js"></script>
<script type="text/javascript">
$(function () {
	
	var filterList = {
	
		init: function () {
		
			// MixItUp plugin
		// http://mixitup.io
		$('#portfoliolist').mixitup({
			targetSelector: '.portfolio',
			filterSelector: '.filter',
			effects: ['fade'],
			easing: 'snap',
			// call the hover effect
			onMixEnd: filterList.hoverEffect()
		});				
	
	},
	
	hoverEffect: function () {
	
		// Simple parallax effect
		$('#portfoliolist .portfolio').hover(
			function () {
				$(this).find('.label').stop().animate({bottom: 0}, 200, 'easeOutQuad');
				$(this).find('img').stop().animate({top: -30}, 500, 'easeOutQuad');				
			},
			function () {
				$(this).find('.label').stop().animate({bottom: -40}, 200, 'easeInQuad');
				$(this).find('img').stop().animate({top: 0}, 300, 'easeOutQuad');								
			}		
		);				
	
	}

};

// Run the show!
	filterList.init();
	
});	
</script>
<!--Blog-Starts-Here-->
	<div class="blog">
		<div class="container">
			<div class="blog-main">
				<div class="col-md-4 blog-left">
					<div class="blog-one wow bounceInLeft" data-wow-delay="0.4s">
						<img src="images/blog-1.png" alt="" />
						<h3>RESUME</h3>
						<p>Lorem Ipsum is not simply random text. It has roots in a piece of classical Latin literature from 45 BC, making it over 2000</p>
					</div>
				</div>
				<div class="col-md-4 blog-left">
					<div class="blog-one wow bounce" data-wow-delay="0.1s">
						<img src="images/blog-4.png" alt="" />
						<h3>BLOG</h3>
						<p>Random text. It has roots in a piece of classical Latin literature from 45 BC, making it over 2000 </p>
					</div>
				</div>
				<div class="col-md-4 blog-left active">
					<div class="blog-one wow bounceInRight" data-wow-delay="0.4s">
						<img src="images/blog-3.png" alt="" />
						<h3>OTHERS</h3>
						<p>Lorem Ipsum is not simply random text. Latin literature from 45 BC, making it over 2000 years old</p>
					</div>
				</div>
				<div class="clearfix"></div>
			</div>
		</div>
	</div>
<!--Blog-Ends-Here-->
<!--Contact-Starts-Here-->
	<div class="contact" id="contact">
		<div class="container">
			<div class="contact-main">
				<div class="col-md-6 contact-left wow bounceInLeft" data-wow-delay="0.4s">
					<h3>Contact Me</h3>
					<p>Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. </p>
					<p>It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.</p>
					<ul>
						<li><p>T: 212-555-1211</p></li>
						<li><p><a href="mailto:example@email.com"> E: info@techandall.com </a></p></li>
						<li><p>F:<a href="#"> facebook.com/techandall</a></p></li>
					</ul>
				</div>
				<div class="col-md-6 contact-left wow bounceInRight" data-wow-delay="0.4s">
					<input type="text" value="Name" onfocus="this.value = '';" onblur="if (this.value == '') {this.value = 'Name';}"/>
					<input type="text" value="Email address" onfocus="this.value = '';" onblur="if (this.value == '') {this.value = 'Email address';}"/>
					<div class="contact-textarea">
						<textarea value="Your question" onfocus="this.value = '';" onblur="if (this.value == '') {this.value = 'Your question';}">Your question</textarea>
					</div>
					<div class="contact-but">
						<input type="submit" value="SEND" />
					</div>
				</div>
				<div class="clearfix"></div>
			</div>
		</div>
	</div>
<!--Contact-Ends-Here-->
<!--Footer-Starts-Here-->
	<div class="footer">
		<div class="conatiner">
			<div class="footer-text wow bounce" data-wow-delay="0.1s">
				<p>TEMPLATE BY <a href="http://w3layouts.com/"> W3LAYOUTS</a></p>
				<ul>
					<li><a href="#"><span class="twt"> </span></a></li>
					<li><a href="#"><span class="t"> </span></a></li>
					<li><a href="#"><span class="g"> </span></a></li>
				</ul>
			</div>
		</div>
		 <script type="text/javascript">
									$(document).ready(function() {
										/*
										var defaults = {
								  			containerID: 'toTop', // fading element id
											containerHoverID: 'toTopHover', // fading element hover id
											scrollSpeed: 1200,
											easingType: 'linear' 
								 		};
										*/
										
										$().UItoTop({ easingType: 'easeOutQuart' });
										
									});
								</script>
		<a href="#home" id="toTop" class="scroll" style="display: block;"> <span id="toTopHover" style="opacity: 1;"> </span></a>
	</div>
<!--Footer-Ends-Here-->
</body>
</html>