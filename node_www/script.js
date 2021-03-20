let lamp = (num, state) => {
    $.ajax({ url: `/api/${num}/${state}` }).done((res) => {
        alert(res);
    });
}