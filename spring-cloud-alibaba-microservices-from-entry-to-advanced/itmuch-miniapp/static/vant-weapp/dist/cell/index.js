import { link } from '../mixins/link';
import { VantComponent } from '../common/component';
VantComponent({
  classes: ['title-class', 'label-class', 'value-class', 'right-icon-class'],
  mixins: [link],
  props: {
    title: null,
    value: null,
    icon: String,
    size: String,
    label: String,
    center: Boolean,
    isLink: Boolean,
    required: Boolean,
    clickable: Boolean,
    titleWidth: String,
    customStyle: String,
    arrowDirection: String,
    border: {
      type: Boolean,
      value: true
    }
  },
  computed: {
    cellClass: function cellClass() {
      var data = this.data;
      return this.classNames('custom-class', 'van-cell', {
        'van-cell--center': data.center,
        'van-cell--required': data.required,
        'van-cell--borderless': !data.border,
        'van-cell--clickable': data.isLink || data.clickable,
        ["van-cell--" + data.size]: data.size
      });
    },
    titleStyle: function titleStyle() {
      var titleWidth = this.data.titleWidth;
      return titleWidth ? "max-width: " + titleWidth + ";min-width: " + titleWidth : '';
    },
    iconWrapClass: function iconWrapClass() {
      var prefix = 'van-cell__right-icon-wrap right-icon-class';
      return this.classNames(prefix, prefix + "--" + this.data.arrowDirection);
    }
  },
  methods: {
    onClick: function onClick(event) {
      this.$emit('click', event.detail);
      this.jumpLink();
    }
  }
});