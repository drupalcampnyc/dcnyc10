<?php if(!empty($days) && !empty($rooms) && !empty($arranged_slots)): ?>
<?php if (!empty($day_links)): ?>
<ul>
<?php foreach ($day_links as $link): ?>
<li><?php print $link; ?></li>
<?php endforeach ?>
</ul>
<?php endif ?>
<?php foreach ($days as $day_key => $day_title): ?>
  <h2><?php print $day_title; ?></h2>
  <table class="session-calendar">
    <tr>
      <th><?php print t('Time'); ?></th>
      <?php foreach ($rooms as $room_nid => $room): ?>
      <?php if ($show_rooms[$day_key][$room_nid]): ?>
        <th><span class="room-label"><?php print $room['title']; ?></span><?php if(!empty($room['sponsor'])): ?><div class="sponsor-label"><?php print $room['sponsor']; ?></div><?php endif; ?></th>
      <?php endif; ?>
      <?php endforeach ?>
    </tr>
    <?php foreach ($arranged_slots[$day_key] as $slot): ?>
    <tr class="<?php print $zebra = $zebra == 'even' ? 'odd':'even'; ?> <?php print $slot['class']; ?>">
        <td class="time-label">
          <?php print $slot['start']; ?>&nbsp;-<br /><?php print $slot['end']; ?>
        </td>
        <?php foreach ($room_nids as $room_nid): ?>
            <?php // Are there scheduled items to print in this cell?
            if (!empty($schedule_grid[$day_key][$slot['nid']][$room_nid]['sessions'])): ?>
              <td class="session occupied<?php print $schedule_grid[$day_key][$slot['nid']][$room_nid]['class']; ?>" colspan="<?php print $schedule_grid[$day_key][$slot['nid']][$room_nid]['colspan']; ?>">
              <?php foreach($schedule_grid[$day_key][$slot['nid']][$room_nid]['sessions'] as $session): ?>
                <div class="views-item type-<?php print check_plain($session['session']->type); ?>">
                <?php print $view_results[$session['session']->nid]; ?>
                </div>
              <?php endforeach ?>
              <?php // Room availability if set.
              if (isset($schedule_grid[$day_key][$slot['nid']][$room_nid]['availability'])): ?>
                <div><?php print $schedule_grid[$day_key][$slot['nid']][$room_nid]['availability']; ?></div>
              <?php endif ?>
              <?php // Cell call-to-action if set.
              if (isset($schedule_grid[$day_key][$slot['nid']][$room_nid]['cta'])): ?>
                <div><?php print $schedule_grid[$day_key][$slot['nid']][$room_nid]['cta']; ?></div>
              <?php endif ?>
            <?php // Print a cell if it's not being spanned.
            elseif (!$schedule_grid[$day_key][$slot['nid']][$room_nid]['spanned'] && $show_rooms[$day_key][$room_nid]): ?>
              <td class="session empty">&nbsp;
              <?php // Room availability if set.
              if (isset($schedule_grid[$day_key][$slot['nid']][$room_nid]['availability'])): ?>
                <div><?php print $schedule_grid[$day_key][$slot['nid']][$room_nid]['availability']; ?></div>
              <?php endif ?>
              <?php // Cell call-to-action if set.
              if (isset($schedule_grid[$day_key][$slot['nid']][$room_nid]['cta'])): ?>
                <div><?php print $schedule_grid[$day_key][$slot['nid']][$room_nid]['cta']; ?></div>
              <?php endif ?>
            <?php endif ?>
            
            <?php // Only end the table cell if there were items or spanning.
            if (!empty($schedule_grid[$day_key][$slot['nid']][$room_nid]['sessions']) || !$schedule_grid[$day_key][$slot['nid']][$room_nid]['spanned']): ?>
              </td>
            <?php endif ?>
        <?php endforeach ?>
    </tr>
    <?php endforeach ?>
  </table>
<?php endforeach ?>
<?php endif ?>