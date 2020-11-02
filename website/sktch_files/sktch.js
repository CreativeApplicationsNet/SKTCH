$(function(){
	$('#email-signup input').one('click', function(){
		$(this).addClass('active').attr('value', '');
    });

    $(".ss").fancybox({
        hideOnContentClick: true,
        zoomSpeedIn: 200,
        zoomSpeedOut: 200,
        overlayShow: true,
        overlayOpacity: .3
    });
    $(".sd").fancybox({
        hideOnContentClick: true,
        zoomSpeedIn: 200,
        zoomSpeedOut: 200,
        overlayShow: true,
        overlayOpacity: .3
    });
    $(".tweet").tweet({
        username: "outpostapp",
        join_text: "auto",
        avatar_size: 32,
        count: 1,
        auto_join_text_default: "we said,", 
        auto_join_text_ed: "we",
        auto_join_text_ing: "we were",
        auto_join_text_reply: "we replied to",
        auto_join_text_url: "we were checking out",
        loading_text: ""
    });
})