function init() {
    let input_elements = document.querySelectorAll('.fancy-input input');

    input_elements.forEach(element => {
        console.log(element);
        scale_label(element, true);
        element.addEventListener('focus', function() { scale_label(element, false); });
        element.addEventListener('blur', function() { scale_label(element, true); });
    });
}

function scale_label(element, is_like_placeholder) {
    if (is_like_placeholder) {
        if (element.value === '') {
            element.parentNode.querySelector('label').classList.add('like-placeholder');
        }
    }
    else {
        element.parentNode.querySelector('label').classList.remove('like-placeholder');
    }
}

document.addEventListener('DOMContentLoaded', init);