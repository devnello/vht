import gi
gi.require_version('Gtk', '3.0')
from gi.repository import Gtk, Gio
import cairo

class TrackSideView(Gtk.DrawingArea):
	def __init__(self, seq):
		Gtk.DrawingArea.__init__(self)
		
		self.connect("draw", self.on_draw);

		self.seq = seq
		self.nrows = seq.length
		self.highlight = 4
		self.padding = 3
		self.add_tick_callback(self.tick)
	
	def tick(self, wdg, param):
		self.queue_draw()
		return 1
		
	def on_realize(self, widget):
		pass
		
	def on_draw(self, widget, cr):
		w = widget.get_allocated_width()
		h = widget.get_allocated_height()
		cr.set_source_rgb(0,.3,0)
		cr.rectangle(0, 0, w, h)
		cr.fill()
		
		cr.set_source_rgb(0, .8, 0)
		cr.select_font_face("Roboto Mono", cairo.FONT_SLANT_NORMAL, cairo.FONT_WEIGHT_NORMAL )
		cr.set_font_size(12)
		(x, y, width, height, dx, dy) = cr.text_extents("000")
		
		if w != (width + (self.padding * 2)):
			self.set_size_request(width + (self.padding * 2), ((height + (self.padding)) * self.nrows) + self.padding)
		
		for a in range(self.nrows):
			if (a) % self.highlight == 0:
				cr.set_source_rgb(0, 1, 0)		
			else:
				cr.set_source_rgb(0, .7, 0)
					
			cr.move_to(self.padding, (a + 1) * (height + self.padding))	
			cr.show_text("%02d" % a)

		pos = self.seq.pos
		if pos != 0.0:
			yy = int(pos * (height + self.padding))
			cr.move_to(0, yy)
			cr.line_to(w, yy)
			cr.stroke()